# WBD Chaos Engineering

## Dimensions and Skills

工作聚焦于 FaaS（混沌工程），这要求您从平台编排 (EKS/Istio)、可观测性 (Prometheus) 和弹性/混沌 (FIS/Litmus) 三个维度入手。

## WBD

HBO current architecture -> BOLT architecture
HBO previous problems and RCA - study old problems, test for Chaos engineering, 80/20 to prioritize
Related Teams and POCs - better understand architecture, impact & scopes of Chaos engineering; regular 1:1

## Fault as a Service (FaaS)

Current: who/ which team, what, how, when, how to verify; current scope; gap to future

---

## BOLT

**Bolt** 是 WBD 内部打造的一套**统一后端平台（Unified Backend Platform）**。它的出现是为了解决一个巨大的技术债：由于 WBD 是由多家媒体公司（如 Discovery 和 WarnerMedia）合并而成的，不同平台（如 HBO Max, Discovery+, Eurosport）原本都有各自独立的后端架构。

以下是 BOLT 的核心要点和它为什么对 WBD 如此重要：

### 1. 为什么叫 BOLT（统一与效率）

在合并之后，WBD 的首席技术官 (CTO) Avi Saxena 启动了 Bolt 项目。它的核心目标是：**“一套后端，支持全球所有品牌”**。

- **统一性：** 无论你是在看 HBO Max 上的《最后生还者》，还是在 Discovery+ 上看纪录片，底层的账户管理、内容分发、支付系统和元数据处理都是由 Bolt 平台统一承载的。
- **一致性：** 确保在 100 多个国家、几十种语言的设备上，用户体验（比如“继续观看”功能、推荐算法）是同步且高质量的。

### 2. BOLT 解决的关键问题

如果你之前关注过 KEDA 和 HPA 的伸缩问题，那么 Bolt 的设计初衷恰好能对上：

- **高并发压力：** 像《龙之家族》首播时，瞬间会有数千万用户涌入。Bolt 被设计成可以极速伸缩的架构，能够应对这种“爆发式”流量。
- **复杂的内容编排：** WBD 拥有极其庞大的资源库（从体育直播到经典电影）。Bolt 作为一个中枢，负责把这些复杂的内容标签化，并快速推送到不同的前端 App 上。

### 3. 与 KEDA 的关联

虽然你提到的“BOLT”是业务平台名，但从技术架构上看，它在底层大量应用了你之前感兴趣的**云原生技术**。

- 为了支撑 Bolt 这样庞大的全球服务，WBD 的技术团队必须处理复杂的**弹性伸缩（Scaling）**逻辑。
- 你之前提到的 KEDA 获取信息不及时的问题，很可能就是 Bolt 团队在尝试用事件驱动（Event-driven）的方式来优化后端服务响应时遇到的挑战。

### 4. 行业背景

- **HBO Max 变身 Max：** 2023 年至 2024 年间，HBO Max 在美国等地更名为 “Max”。这次大迁移背后的技术底座正是 Bolt。它让 WBD 能够把 Discovery+ 的海量内容无缝合并到原有的 HBO 架构中。
- **AI 的加入：** 最新的消息显示，Bolt 平台正在引入 AI 来优化内容推荐和系统测试。

### 总结一下

**BOLT** 就是 WBD  streaming 业务的**超级引擎**。

- **WBD/HBO Max** 是车壳和品牌。
- **BOLT** 是发动机和底盘。
- **KEDA/HPA** 是发动机里的自动调节气门（伸缩机制）。

---

## 关于BOLT的深度解析

关于 **BOLT**，这在流媒体技术圈（尤其是北美 WBD 团队）是一个非常硬核的话题。它不仅是一个后端平台，更是 WBD 媒体帝国技术转型的核心。

### 1. 名字由来与读法

- **名字含义：** BOLT 并非某个长句子的缩写（Acronym），而是一个**意向性名字**。它取自“闪电”（Lightning Bolt）的含义，象征着**极速（Speed）**、**能量（Power）**和**连接（Connection）**。在合并了 WarnerMedia 和 Discovery 的复杂背景下，这个名字代表了团队希望技术架构能够像闪电一样快速响应全球亿万用户的需求。
- **怎么读：** 读音与英文单词 **"bolt"** 完全一致，音标为 **/boʊlt/**（类似于中文拼音“波特”，但末尾带轻声 't'）。

### 2. 架构概览 (Architecture)

BOLT 的核心架构理念是 **“Global, Unified, and Scalable”**。它摒弃了过去那种为每个地区或品牌单独构建烟囱式系统的做法。

#### 核心架构组件

- **多租户抽象层 (Multi-tenant Layer)：** 一套代码同时支持 Max、Discovery+、CNN 等不同品牌。通过配置而非硬编码来区分品牌逻辑。
- **事件驱动架构 (EDA)：** 这就是为什么你会听到 **KEDA**。BOLT 大量使用异步消息（如 Kafka、SQS）来触发任务。
- **微服务联邦 (Microservices Federation)：** 采用 GraphQL 联邦架构，让前端可以通过一个统一的入口（Supergraph）访问后台数百个微服务（用户、支付、内容元数据等）。
- **全球分布式数据平面：** 利用 AWS 的多区域（Multi-region）部署，确保用户数据在离他最近的节点处理，减少播放卡顿。

### 3. 开发背景：什么时候开始的？

BOLT 的大规模开发始于 **2022 年 4 月** Warner Bros. 与 Discovery 正式合并之后。

- **起因：** 当时 CTO Avi Saxena（前 Amazon 高管）面临一个巨大的挑战：HBO Max 当时的架构在处理《龙之家族》等超大流量时非常吃力，且维护成本极高。
- **转折点：** 2023 年 5 月，Max 在美国正式上线，标志着 BOLT 平台完成了第一次真正的全球级实战验证。

### 4. 它解决旧问题了吗？

**答案是肯定的，它非常有效地解决了以下三个顽疾：**

1. **发布效率：** 以前更新一个功能（如“个性化推荐”）需要为三个 App 改三遍代码。现在在 BOLT 上改一次，全球所有品牌同步生效。
2. **弹性伸缩 (Scalability)：** 借助你提到的 KEDA 等技术，它实现了“预测性扩容”。在热门大剧上线前的几分钟，系统能根据历史模型自动拉起数千个 Pod，而不是等流量打爆了 CPU 才动作。
3. **成本优化：** 通过统一平台，减少了大量的重复基础设施支出。

### 5. 它的缺点和瓶颈是什么？

没有任何架构是完美的，BOLT 也有其明显的“成长的烦恼”：

- **过度中心化的风险 (Single Point of Failure)：** 因为所有品牌都跑在一个平台上，如果 BOLT 的核心逻辑出问题（比如你提到的 KEDA 指标获取不及时导致扩容失败），可能导致全球所有品牌集体瘫痪。
- **信息获取的延迟（即你提到的 KEDA 问题）：**
  - **瓶颈：** 由于 BOLT 规模巨大，它依赖的底层信息源（如某些遗留的元数据数据库）在高频访问下会变慢。
  - **现状：** KEDA 如果拿不到及时的“活儿有多少”的信息，就会导致伸缩决策失误。
- **内部认知负载 (Cognitive Load)：** 系统太庞大、太抽象。一个新加入的工程师可能需要好几个月才能搞清楚 BOLT 内部复杂的 YAML 配置和事件流向。
- **“一刀切”的灵活性限制：** 有时某个品牌（如 CNN）想要一个极其特殊的功能，但在 BOLT 这种大一统架构下，为了保持标准，可能很难快速满足这种定制化需求。