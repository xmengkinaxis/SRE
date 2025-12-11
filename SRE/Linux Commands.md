
## tree

> tree ./code

## curl

curl = Client URL (command-line HTTP/S client tool)

curl is essentially **HTTP client for terminals** — like a browser, but text-based and programmable.

A command-line tool that lets you send requests to URLs (HTTP, HTTPS, FTP, S3, etc.) and get responses.

| Use case          | Example                                                                             |
| ----------------- | ----------------------------------------------------------------------------------- |
| Test an API       | `curl https://api.github.com`                                                       |
| POST JSON         | `curl -X POST -H "Content-Type: application/json" -d '{"a":1}' https://example.com` |
| Download a file   | `curl -O https://example.com/file.zip`                                              |
| Send auth headers | `curl -H "Authorization: Bearer TOKEN" https://api.example.com/data`                |
| Debug HTTP        | `curl -v https://example.com`                                                       |

## ssh

ssh = Secure Shell (command-line secure remote login tool + protocol implementation)

A secure protocol and tool for logging into remote machines and executing commands over an encrypted channel

| Use case                   | Example                                    |
| -------------------------- | ------------------------------------------ |
| Connect to a remote server | `ssh user@192.168.1.10`                    |
| Use private key            | `ssh -i ~/.ssh/id_rsa user@myserver`       |
| Run a remote command       | `ssh user@server "systemctl status nginx"` |
| Copy files securely        | `scp file.txt user@server:/tmp`            |
| SSH tunnel                 | `ssh -L 8080:localhost:80 user@server`     |

SSH = tool + protocol

- Protocol: defines secure communication principles
- Tool (binary): /usr/bin/ssh

From an SRE perspective 

| Tool | Why SREs care                                                                |
| ---- | ---------------------------------------------------------------------------- |
| curl | API health checks, service debugging, latency test, TLS handshake inspection |
| ssh  | remote server access, incident debugging, log inspection, secure automation  |

e.g.

Check if service is alive and latency
curl -w "Status: %{http_code} Time: %{time_total}\n" -o /dev/null -s https://service.internal/health

Jump-host SSH to prod
ssh -J bastion.company.com sre@prod-node-23

下面给你 **SRE 实战调试链路（完整闭环）**，从报障 → curl → logs → ssh → tracing，一条龙定位故障根因。

---

# 🔥 SRE Production Debugging Golden Workflow

**curl → metrics → logs → ssh → tracing → fix → RCA**

---

## ① Step 1: curl 初步探测（外部视角 / Client POV）

### ❗目标：判断是网络 / DNS / LB / App / TLS 哪一层的问题

```bash
# 基础探活
curl -v https://service.internal/health

# 同时打印耗时与HTTP状态
curl -w "code:%{http_code} time:%{time_total}\n" -o /dev/null -s https://service.internal/api
```

### 判断维度：

| 结果          | 说明                                     |
| ----------- | -------------------------------------- |
| TCP 失败      | 网络 / LB / 防火墙                          |
| TLS 握手失败    | 证书 / cipher mismatch / trust chain     |
| HTTP 200 但慢 | backend 饱和 / DB 慢查询                    |
| HTTP 500    | 应用 bug / downstream 挂掉                 |
| HTTP 503    | 负载过高 / readiness fail / autoscaling 异常 |

---

## ② Step 2: Metrics Dashboard (30s 快速结论)

**Grafana / Datadog / Prometheus**

看 3 个指标即可：

| 指标          | 优先级 | 要判断什么             |
| ----------- | --- | ----------------- |
| RPS         | 1   | 流量突然暴涨？           |
| Error Rate  | 2   | Error Budget 是否爆？ |
| Latency P99 | 3   | 下游谁导致尾延迟？         |

**辅助：**

* Saturation（CPU、Memory、FDs、Thread pool）
* Queue length
* Pod eviction

---

## ③ Step 3: Logs（服务内部视角）

### App Logs（关键）

```bash
kubectl logs deploy/service -f --tail=200
```

### 分析Focus：

* 5xx 栈追踪
* 超时日志（`timeout`, `deadline exceeded`）
* 下游依赖错误（Redis, MySQL, Kafka）

### Infra Logs:

```bash
journalctl -u nginx --since "10 min ago"
journalctl -u service --no-pager -f
```

### 如果日志大量 timeout：

👉 不是服务挂了，是它在等待别人
可继续走 tracing。

---

## ④ Step 4: ssh 到节点（必要时）

⚠️ 适用于节点/网关/LB 调试，而非直接进生产 Pod（除非有安全策略允许）

```bash
ssh sre@node-23.prod.company
top -o %CPU
dmesg | tail
sudo lsof -i :443
sudo netstat -plant | grep service
```

检查 3 项：

| 检查项      | 问题信号                        |
| -------- | --------------------------- |
| CPU      | 负载飙升 → Thread starvation    |
| Memory   | OOM / swap / cgroup kill    |
| Disk I/O | 延迟上升 → DB / Log flush 变慢    |
| Logs     | kernel kill processes / OOM |

---

## ⑤ Step 5: Distributed Tracing（根因确认）

Jaeger / Zipkin / OpenTelemetry

查看 **链路耗时分布**：

| Trace 显示                 | 根因                              |
| ------------------------ | ------------------------------- |
| Redis span 最慢            | cache miss / hot key / eviction |
| DB span 占比高              | index 丢失 / 死锁 / 慢查询             |
| internal service call 失败 | 依赖服务挂或超时                        |
| queue span blocking      | downstream 拥塞                   |

**你要找的不是错误，而是 variance（抖动/尾延迟）**

---

# 🔍 整体调试流程一张图

```
   curl
    ↓
 metrics (RPS / Error / P99)
    ↓
   logs (who is failing?)
    ↓
   ssh (resource & OS validation)
    ↓
 tracing (where latency explodes?)
    ↓
 RCA (root cause & prevention)
```

---

# 🧠 真实案例快速模拟

## 现象

* 用户反馈 API 慢
* SLO violation

### 1. curl 结果

```
code:200 time:2.8s   ❗高延迟
```

### 2. Metrics

* P99 → 3s（上升）
* Redis QPS 下降
* Error stable

### 3. Logs

```
redis timeout, retrying...
```

### 4. Tracing

```
Redis span = 2.5s
  ↓
Root cause: single hot key lock
```

### 5. SSH 到 Redis 节点

锁竞争导致查询放大 (cache stampede)

---

# ✔ Fix & Prevention

| 问题             | 对策                                        |
| -------------- | ----------------------------------------- |
| cache stampede | 加入 request coalescing / lock / TTL jitter |
| 单点热键           | sharding / 分区 hashing                     |
| Redis overload | 调高 maxclients，接入 connection pool          |
| 尾延迟            | 使用异步队列 / bulk 获取 / 分层缓存                   |

---

# 📌 Bonus: SRE 事故复盘模板 (Blameless RCA)

```
Title:
Timeline:
Impact:
Root Cause:
Trigger:
Detection gap:
Mitigation:
Prevention:
Metrics effect:
Error budget consumed:
Action items:
Owner:
Deadline:
```

---

如果你愿意，我可以整理成：

📘《SRE Debugging Playbook 》（带图、流程图、真实案例、RCA 模板）

* 15–25 页
* 专门用于 Oncall & Incident response
* 可用于 WBD / Meta / Netflix 等团队 onboarding

需要吗？
