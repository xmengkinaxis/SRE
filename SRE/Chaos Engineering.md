# Chaos Engineering

- [Chaos Engineering](#chaos-engineering)
  - [PRINCIPLES OF CHAOS ENGINEERING](#principles-of-chaos-engineering)
    - [ADVANCED PRINCIPLES](#advanced-principles)
      - [Build a Hypothesis around Steady State Behavior](#build-a-hypothesis-around-steady-state-behavior)
      - [Vary Real-world Events](#vary-real-world-events)
      - [Run Experiments in Production](#run-experiments-in-production)
      - [Automate Experiments to Run Continuously](#automate-experiments-to-run-continuously)
      - [Minimize Blast Radius](#minimize-blast-radius)
    - [Summary](#summary)
  - [Principles of Chaos（混沌工程原则）](#principles-of-chaos混沌工程原则)
    - [什么是混沌工程？](#什么是混沌工程)
    - [混沌工程的五大核心原则](#混沌工程的五大核心原则)
      - [1. 建立关于“稳态”的假设 (Build a Hypothesis around Steady State Behavior)](#1-建立关于稳态的假设-build-a-hypothesis-around-steady-state-behavior)
      - [2. 模拟现实世界的事件 (Vary Real-world Events)](#2-模拟现实世界的事件-vary-real-world-events)
      - [3. 在生产环境中运行实验 (Run Experiments in Production)](#3-在生产环境中运行实验-run-experiments-in-production)
      - [4. 持续自动化实验 (Automate Experiments to Run Continuously)](#4-持续自动化实验-automate-experiments-to-run-continuously)
      - [5. 最小化“爆炸半径” (Minimize Blast Radius)](#5-最小化爆炸半径-minimize-blast-radius)
    - [实验的基本流程](#实验的基本流程)
    - [总结：为什么我们要这么做？](#总结为什么我们要这么做)
  - [故障 (Faults) 的定义、分类以及它们的生命周期管理](#故障-faults-的定义分类以及它们的生命周期管理)
    - [故障 (Faults) 的基本概念](#故障-faults-的基本概念)
    - [分类：如何定义和归类故障](#分类如何定义和归类故障)
      - [1. 按持续时间分类](#1-按持续时间分类)
      - [2. 按来源和类型分类](#2-按来源和类型分类)
    - [故障生命周期管理](#故障生命周期管理)
      - [1. 检测 (Detection)](#1-检测-detection)
      - [2. 响应 (Response)](#2-响应-response)
      - [3. 缓解/隔离 (Mitigation/Containment)](#3-缓解隔离-mitigationcontainment)
      - [4. 恢复 (Resolution)](#4-恢复-resolution)
      - [5. 事后分析 (Postmortem/Root Cause Analysis)](#5-事后分析-postmortemroot-cause-analysis)
      - [6. 预防/改进 (Prevention/Improvement)](#6-预防改进-preventionimprovement)
  - [混沌工程 (Chaos Engineering)](#混沌工程-chaos-engineering)
    - [介绍](#介绍)
    - [混沌工程的核心目标](#混沌工程的核心目标)
    - [混沌工程的实验步骤](#混沌工程的实验步骤)
      - [1. 制定稳态假设 (Define the Steady State)](#1-制定稳态假设-define-the-steady-state)
      - [2. 设计和执行实验 (Hypothesize and Execute)](#2-设计和执行实验-hypothesize-and-execute)
      - [3. 扩大破坏范围 (Increase the Scope)](#3-扩大破坏范围-increase-the-scope)
    - [4. 修复和自动化 (Remediate and Automate)](#4-修复和自动化-remediate-and-automate)
    - [混沌工程与传统测试的区别](#混沌工程与传统测试的区别)
  - [AWS Fault Injection Service (AWS FIS)](#aws-fault-injection-service-aws-fis)
    - [核心概念：混沌工程自动化](#核心概念混沌工程自动化)
      - [1. 实验模板 (Experiment Template)](#1-实验模板-experiment-template)
      - [2. 操作 (Actions)](#2-操作-actions)
      - [3. 目标 (Targets)](#3-目标-targets)
      - [4. 安全杆 (Safety Lever)](#4-安全杆-safety-lever)
    - [AWS FIS 的价值](#aws-fis-的价值)
  - [Chaos Mesh](#chaos-mesh)
    - [Chaos Mesh 的核心定位](#chaos-mesh-的核心定位)
    - [核心组件与工作原理](#核心组件与工作原理)
      - [1. Chaos Controller Manager (混沌控制器管理器)](#1-chaos-controller-manager-混沌控制器管理器)
      - [2. Chaos Daemon (混沌守护进程)](#2-chaos-daemon-混沌守护进程)
      - [3. Chaos Dashboard (混沌仪表盘)](#3-chaos-dashboard-混沌仪表盘)
    - [Chaos Mesh 提供的故障类型](#chaos-mesh-提供的故障类型)
    - [使用 Chaos Mesh 的优势](#使用-chaos-mesh-的优势)
  - [LitmusChaos](#litmuschaos)
    - [LitmusChaos 的核心概念](#litmuschaos-的核心概念)
      - [1. Chaos Experiments (混沌实验)](#1-chaos-experiments-混沌实验)
      - [2. Chaos Operator (混沌操作器)](#2-chaos-operator-混沌操作器)
      - [3. ChaosCenter (控制面板)](#3-chaoscenter-控制面板)
    - [核心工作流程：Chaos Workflows](#核心工作流程chaos-workflows)
    - [LitmusChaos 的主要优势](#litmuschaos-的主要优势)
  - [GitHub Actions (GHA)](#github-actions-gha)
    - [1. GHA (GitHub Actions) 的定义](#1-gha-github-actions-的定义)
    - [2. GHA 与混沌工程的关联：Chaos in CI/CD](#2-gha-与混沌工程的关联chaos-in-cicd)
      - [工作原理](#工作原理)
      - [总结关联](#总结关联)
    - [3. 识别 FaaS 相关的 GHA](#3-识别-faas-相关的-gha)
    - [GHA + LitmusChaos 流程示例](#gha--litmuschaos-流程示例)
      - [1. 场景设置](#1-场景设置)
      - [2. GHA Workflow (`.github/workflows/chaos-test.yaml`)](#2-gha-workflow-githubworkflowschaos-testyaml)
      - [流程解释](#流程解释)
  - [AWS FIS (云服务)、Chaos Mesh (K8s) 和 LitmusChaos (K8s) 的比较、分析和综合](#aws-fis-云服务chaos-mesh-k8s-和-litmuschaos-k8s-的比较分析和综合)
    - [三大混沌工程平台的比较与分析](#三大混沌工程平台的比较与分析)
    - [共同之处与差异点](#共同之处与差异点)
      - [共同之处 (Commonalities)](#共同之处-commonalities)
      - [主要差异 (Key Differences)](#主要差异-key-differences)
    - [重叠、互补与协同使用](#重叠互补与协同使用)
      - [重叠性 (Overlap)](#重叠性-overlap)
      - [互补性 (Complementarity)](#互补性-complementarity)
      - [协同使用示例](#协同使用示例)
    - [如何与 GHA 和谐整合？](#如何与-gha-和谐整合)
      - [GHA 整合流程 (以 LitmusChaos 为例)](#gha-整合流程-以-litmuschaos-为例)
  - [分层自动化混沌验证系统的最佳实践](#分层自动化混沌验证系统的最佳实践)
    - [整体策略：分层测试模型](#整体策略分层测试模型)
    - [分层组合与编排的详细步骤](#分层组合与编排的详细步骤)
      - [Step 0: 前置条件与假设定义](#step-0-前置条件与假设定义)
      - [Step 1: L1 基础设施层故障注入 (AWS FIS)](#step-1-l1-基础设施层故障注入-aws-fis)
      - [Step 2: L2 K8s/内核层故障注入 (Chaos Mesh)](#step-2-l2-k8s内核层故障注入-chaos-mesh)
      - [Step 3: L3 应用/业务流程故障注入 (LitmusChaos)](#step-3-l3-应用业务流程故障注入-litmuschaos)
    - [结合 GHA 的自动化编排优势](#结合-gha-的自动化编排优势)
      - [GHA 中的关键逻辑示例（伪代码）](#gha-中的关键逻辑示例伪代码)
  - [AWS Fault Injection Service (AWS FIS)](#aws-fault-injection-service-aws-fis-1)
    - [Planning AWS FIS Experiments](#planning-aws-fis-experiments)
      - [Basic principles and guidelines](#basic-principles-and-guidelines)
      - [Experiment Planning Guidelines](#experiment-planning-guidelines)
  - [AWS FIS（Fault Injection Service）的 YAML](#aws-fisfault-injection-service的-yaml)
    - [AWS FIS YAML 的组织逻辑：三位一体](#aws-fis-yaml-的组织逻辑三位一体)
      - [1. Targets (目标：对谁做？)](#1-targets-目标对谁做)
      - [2. Actions (动作：做什么？)](#2-actions-动作做什么)
      - [3. Stop Conditions (止损：什么时候停？)](#3-stop-conditions-止损什么时候停)
    - [一个具体的 AWS FIS YAML 例子](#一个具体的-aws-fis-yaml-例子)
      - [为什么看起来复杂？](#为什么看起来复杂)
    - [学习参考资料](#学习参考资料)
  - [AWS SSM（Systems Manager）文档](#aws-ssmsystems-manager文档)
    - [SSM 文档的基本语法结构](#ssm-文档的基本语法结构)
    - [为什么你会看到 `if` 语句？](#为什么你会看到-if-语句)
    - [SSM 原生的“逻辑控制”语句](#ssm-原生的逻辑控制语句)
      - [1. `precondition` (预设条件)](#1-precondition-预设条件)
      - [2. `nextStep` 和 `finallyStep` (分支跳转)](#2-nextstep-和-finallystep-分支跳转)
      - [3. `timeoutSeconds` (超时控制)](#3-timeoutseconds-超时控制)
    - [总结：如何快速读懂它？](#总结如何快速读懂它)
      - [常用参考资料](#常用参考资料)
  - [Bash in YAML](#bash-in-yaml)
    - [1. 最核心的逻辑：`if` 语句（判断）](#1-最核心的逻辑if-语句判断)
      - [常见条件判断符号](#常见条件判断符号)
    - [2. 变量：存储信息](#2-变量存储信息)
    - [3. 常见命令（你在 FIT 脚本中常看到的）](#3-常见命令你在-fit-脚本中常看到的)
    - [4. 组合指令：`&&` 和 `||`](#4-组合指令-和-)
    - [5. 实战翻译：带你读一段 FIT 脚本](#5-实战翻译带你读一段-fit-脚本)
    - [快速看懂的三个窍门](#快速看懂的三个窍门)
  - [AWS FIS/SSM 文档中经常出现的几类“模版化”的 Shell 脚本](#aws-fisssm-文档中经常出现的几类模版化的-shell-脚本)
    - [模式一：环境自愈与工具安装 (The "Check-and-Install" Pattern)](#模式一环境自愈与工具安装-the-check-and-install-pattern)
    - [模式二：带保护的破坏指令 (The "Safe Attack" Pattern)](#模式二带保护的破坏指令-the-safe-attack-pattern)
    - [模式三：状态检查与回滚 (The "Validation" Pattern)](#模式三状态检查与回滚-the-validation-pattern)
    - [模式四：变量替换 (The "Placeholder" Pattern)](#模式四变量替换-the-placeholder-pattern)
    - [总结：看懂脚本的“三板斧”](#总结看懂脚本的三板斧)


## [PRINCIPLES OF CHAOS ENGINEERING](https://principlesofchaos.org/)

Chaos Engineering is the discipline of experimenting on a system in order to build confidence in the system’s capability to withstand turbulent conditions in production.

Even when all of the individual services in a distributed system are functioning properly, the interactions between those services can cause unpredictable outcomes.

We need to identify weaknesses before they manifest in system-wide, aberrant behaviors. We need a way to manage the chaos inherent in these systems, take advantage of increasing flexibility and velocity, and have confidence in our production deployments despite the complexity that they represent.

To specifically address the uncertainty of distributed systems at scale, **Chaos Engineering** can be thought of as **the facilitation of experiments to uncover systemic weaknesses**. These experiments follow four steps:

1. Start by defining ‘steady state’ as some measurable output of a system that indicates normal behavior.
1. Hypothesize that this steady state will continue in both the control group and the experimental group.
1. Introduce variables that reflect real world events like servers that crash, hard drives that malfunction, network connections that are severed, etc.
1. Try to disprove the hypothesis by looking for a difference in steady state between the control group and the experimental group.

The harder it is to disrupt the steady state, the more confidence we have in the behavior of the system. If a weakness is uncovered, we now have a target for improvement before that behavior manifests in the system at large.

NOTE: 

- Steady state: ideal state
- States and their assumptions/foundations
- break these assumptions, foundations, and States
- Prove the system can self-heal back
- Can gracefully and smoothly back to the Steady state after disaster recovering

### ADVANCED PRINCIPLES

describe an ideal application of Chaos Engineering, applied to the processes of experimentation 

#### Build a Hypothesis around Steady State Behavior

Focus on the measurable output of a system, rather than internal attributes of the system.

The overall system’s throughput, error rates, latency percentiles, etc. could all be metrics of interest representing steady state behavior.

Chaos verifies that the system does work, rather than trying to validate how it works.

#### Vary Real-world Events

- Chaos variables reflect real-world events.
- Prioritize events either by potential impact or estimated frequency.
- Any event capable of disrupting steady state is a potential variable in a Chaos experiment.

#### Run Experiments in Production

Systems behave differently depending on environment and traffic patterns. Sampling real traffic is the only way to reliably capture the request path. Chaos strongly prefers to experiment directly on production traffic.

#### Automate Experiments to Run Continuously

- Running experiments manually is labor-intensive and ultimately unsustainable.
- Automate experiments and run them continuously.
- Chaos Engineering builds automation into the system to drive both orchestration and analysis.

#### Minimize Blast Radius

Experimenting in production has the potential to cause unnecessary customer pain. It is the responsibility and obligation of the Chaos Engineer to ensure the fallout from experiments are minimized and contained.

### Summary

Chaos specifically tackles systemic uncertainty in these distributed systems. The Principles of Chaos provide confidence to innovate quickly at massive scales and give customers the high quality experiences they deserve.

---

## Principles of Chaos（混沌工程原则）

是混沌工程领域的奠基性文档。它并不是关于如何“搞破坏”的指南，而是关于如何**通过科学实验构建系统弹性（Resilience）**的方法论。

以下是其核心要点的总结：

### 什么是混沌工程？

混沌工程是在分布式系统上进行**实验**的学科，目的是建立对系统抵御生产环境中各种突发故障能力的**信心**。

### 混沌工程的五大核心原则

#### 1. 建立关于“稳态”的假设 (Build a Hypothesis around Steady State Behavior)

不要关注系统的内部指标（如 CPU 使用率），而要关注**可衡量的系统输出**（如每秒订单数、平均响应延迟）。

- **要点：** 定义什么是“正常”。如果系统在故障注入时，这些核心业务指标依然保持稳定，说明系统具有弹性。

#### 2. 模拟现实世界的事件 (Vary Real-world Events)

故障不仅仅是服务器宕机。你应该根据发生概率和潜在影响来排列实验。

- **模拟对象：** 硬件故障、网络延迟、下游服务异常、流量激增、资源耗尽（内存/磁盘）等。

#### 3. 在生产环境中运行实验 (Run Experiments in Production)

这是最具争议但也最重要的原则。

- **理由：** 预发环境（Staging）永远无法完全模拟真实的流量模式、复杂的网络拓扑和真实的数据规模。只有在生产环境中验证，才能获得真正的信心。

#### 4. 持续自动化实验 (Automate Experiments to Run Continuously)

手动测试是一次性的。随着系统代码的迭代，昨天的抗风险能力不代表今天依然有效。

- **要点：** 将混沌实验集成到 CI/CD 流水线中，让实验自动、持续地运行。

#### 5. 最小化“爆炸半径” (Minimize Blast Radius)

混沌工程不是为了真的搞垮系统，而是为了学习。

- **要点：** 实验必须伴随严密的监控。如果实验导致业务指标出现异常波动的迹象，必须能够**立即自动停止**并恢复系统。
- **策略：** 先从一小部分用户或一台服务器开始实验，确认安全后再扩大规模。

### 实验的基本流程

1. **定义稳态：** 确定描述正常行为的指标。
2. **提出假设：** 假设如果注入 X 故障，稳态仍能维持。
3. **注入故障：** 引入变量（如断开一个可用区、模拟网络延迟）。
4. **观察对比：** 对比实验组和对照组的差异。
5. **学习修复：** 如果稳态被破坏，说明找到了弱点，修复它。

### 总结：为什么我们要这么做？

混沌工程的本质是**“主动寻找弱点”**。与其等到凌晨三点被突发的线上事故叫醒，不如在白天、在受控的环境下主动触发这些故障，确保我们的架构（如你之前提到的 Istio、AWS 基础设施）能够自动处理这些异常。

这就解释了你看到的 **AWS FIS YAML** 为什么那么复杂：

- 它需要定义 **Target**（限制爆炸半径）。
- 它需要定义 **Action**（模拟现实事件）。
- 它需要定义 **Stop Condition**（自动化止损）。

---

## 故障 (Faults) 的定义、分类以及它们的生命周期管理

这些知识是理解和实践混沌工程、SRE 和可靠性建设的基础。

### 故障 (Faults) 的基本概念

在系统可靠性工程中，我们通常区分三个相关的概念：

| 概念 | 定义 | 示例 |
| :--- | :--- | :--- |
| **故障 (Fault)** | **系统中的潜在缺陷或错误原因。** 它是导致错误的根源，可能是代码缺陷、硬件损坏、设计错误或人为失误。 | 代码中的一个 Bug、电源线损坏、配置错误。 |
| **错误 (Error)** | **系统在运行过程中产生的不正确状态。** 它是故障的直接结果。 | 内存中的数据损坏、响应延迟超过阈值、计算结果不正确。 |
| **失效/失败 (Failure)** | **系统未能按照预期执行其所需的功能。** 这是用户或外部可见的，是错误的外在表现。 | 网站返回 500 错误、服务完全中断、交易无法完成。 |

**关系：** **Fault (原因) $\rightarrow$ Error (内部状态) $\rightarrow$ Failure (外部结果)**

---

### 分类：如何定义和归类故障

故障可以根据其来源、持续时间和影响范围进行分类。这是实施混沌工程时选择实验变量的基础。

#### 1. 按持续时间分类

| 分类 | 特点 | 示例 |
| :--- | :--- | :--- |
| **瞬时故障 (Transient Fault)** | 出现后很快消失，且不会留下永久性损坏。通常是网络抖动、瞬时资源争抢。 | 短暂的网络丢包、单次 API 调用超时。 |
| **间歇故障 (Intermittent Fault)** | 随机出现和消失，难以重现。通常是时序竞争 (Race Condition) 或资源泄露。 | 间歇性的数据库连接超时，在特定负载下才出现的死锁。 |
| **永久故障 (Permanent Fault)** | 持续存在，直到被检测和修复。 | 磁盘驱动器损坏、代码中的逻辑错误、配置了错误的防火墙规则。 |

#### 2. 按来源和类型分类

| 分类 | 示例 | 影响 |
| :--- | :--- | :--- |
| **硬件故障** | 磁盘 I/O 错误、内存损坏、网卡失效、服务器断电。 | 影响单个节点，可能导致数据丢失。 |
| **软件故障** | 代码 Bug、逻辑错误、内存泄露、程序崩溃、依赖库版本冲突。 | 影响服务实例，通过重启可能解决，但根源未除。 |
| **网络故障** | 延迟 (Latency)、丢包 (Packet Loss)、带宽限制、DNS 解析失败、网络分区 (Network Partition)。 | 影响分布式服务间的通信和外部访问。 |
| **运维/配置故障** | 错误的部署脚本、资源限额设置过低、证书过期、错误的路由配置。 | 通常是影响范围最广、最难以排查的故障之一。 |

---

### 故障生命周期管理

故障生命周期管理 (Fault/Incident Lifecycle Management) 是指从故障的发生到系统恢复和预防的整个流程。在 SRE 实践中，这被称为 **事件管理 (Incident Management)**。

#### 1. 检测 (Detection)

- **目的：** 快速识别故障或潜在故障的发生。
- **工具/实践：** 监控系统、警报 (Alerting) 系统、SLO 违规通知。

#### 2. 响应 (Response)

- **目的：** 确认故障、启动响应流程并通知相关人员。
- **实践：** On-Call 轮值、故障指挥官 (Incident Commander) 指定、沟通渠道建立。

#### 3. 缓解/隔离 (Mitigation/Containment)

- **目的：** 快速采取措施限制故障的影响范围，阻止用户体验进一步恶化。
- **实践：** 回滚部署、重启故障实例、切换到备用数据中心、限流 (Rate Limiting)、关闭非关键功能（降级）。

#### 4. 恢复 (Resolution)

- **目的：** 彻底解决导致失效的根本问题，使系统恢复到健康运行状态。
- **实践：** 修复配置、部署热补丁、扩大资源容量。

#### 5. 事后分析 (Postmortem/Root Cause Analysis)

- **目的：** 记录事件全过程，分析根本原因，并确定预防措施。
- **实践：** **无指责文化 (Blameless Culture)**，撰写 Postmortem 文档，记录时间线、影响、根本原因和行动项。

#### 6. 预防/改进 (Prevention/Improvement)

- **目的：** 基于事后分析的结果，实施变更以防止相同或类似的故障再次发生。
- **实践：** 混沌工程实验（验证修复是否有效）、创建自动化测试、改进监控和告警规则、系统重构。

**掌握这套生命周期管理是 SRE 团队工作的核心**，它将故障从一个突发事件转化为持续改进系统弹性的机会

---

## 混沌工程 (Chaos Engineering)

### 介绍

**混沌工程 (Chaos Engineering)** 是一种在生产环境中**主动地、有计划地引入故障**的工程实践，目的是通过观察系统在这些破坏性事件下的反应，来提高系统的**弹性 (Resilience)** 和**可靠性**。

简单来说，它的核心理念是：**与其被动地等待故障发生，不如主动地、可控地制造故障，来发现和修复系统的弱点。**

---

### 混沌工程的核心目标

混沌工程的主要目标不是为了破坏系统，而是为了获得对系统行为的**信心和理解**。

| 目标 | 说明 |
| :--- | :--- |
| **验证弹性 (Resilience)** | 确认系统能够在组件失效（如网络中断、磁盘故障、服务崩溃）时，依然能保持功能或快速恢复。 |
| **发现盲点** | 找出隐藏在监控指标之下的、只有在压力或故障情境下才会暴露的系统缺陷。 |
| **提升可观测性 (Observability)** | 测试监控和告警系统是否能够在故障发生时及时、准确地发出警报。 |
| **提高团队信心** | 通过周期性、可控的实验，让开发和运维团队熟悉故障模式，增强对系统的掌控感。 |

---

### 混沌工程的实验步骤

混沌工程的实践不是随意的破坏，而是一个严谨的科学实验过程，通常遵循以下四个步骤：

#### 1. 制定稳态假设 (Define the Steady State)

- **定义：** 确定一个在实验期间应该保持不变的可观测、可衡量的系统指标，这通常是业务指标，而不是技术指标。
- **示例：** 在接下来的 30 分钟内，用户购物车的加载时间应保持在 500 毫秒以下，且订单成功率保持在 99% 以上。

#### 2. 设计和执行实验 (Hypothesize and Execute)

- **假设：** 预测引入故障后，系统将如何保持稳态。
- **实验：** 在生产或准生产环境中，对部分流量或实例**引入故障**。
  - **示例：** 随机终止 5% 的 Web 服务器 EC2 实例。
  - **工具：** AWS FIS、Chaos Mesh (K8s)、LitmusChaos 等。

#### 3. 扩大破坏范围 (Increase the Scope)

- 如果系统成功地抵御了小范围的故障，并且稳态没有被打破，那么逐渐增加实验的强度和范围。
- **目的：** 寻找系统能够承受的临界点。

### 4. 修复和自动化 (Remediate and Automate)

- **发现弱点：** 如果实验打破了稳态假设（即系统崩溃或用户体验受损）：
    1. 立即停止实验（安全机制）。
    2. 分析根本原因。
    3. **修复**发现的缺陷（如添加重试逻辑、改进降级策略）。
- **自动化：** 将已修复的故障场景转化为**自动化测试**，确保系统在未来的版本更新中不会重新引入相同的漏洞。

### 混沌工程与传统测试的区别

| 特性 | 传统测试（单元/集成） | 混沌工程 |
| :--- | :--- | :--- |
| **环境** | 预生产、测试环境 | **生产环境（或高保真环境）** |
| **目标** | 验证系统按预期工作 | 验证系统在**非预期**情况下如何工作 |
| **侧重** | 功能正确性 | **系统弹性 (Resilience)** |
| **时间** | 持续进行或在部署前进行 | **持续、周期性地**运行 |

**总结：** 混沌工程不是测试代码的功能，而是测试**整个分布式系统**在压力、延迟和组件失效时的**行为和架构**。

---

## AWS Fault Injection Service (AWS FIS)

中文译为 **AWS 故障注入服务**，是亚马逊网络服务（AWS）提供的一项**托管服务**，用于帮助用户基于**混沌工程 (Chaos Engineering)** 原理，对他们在 AWS 上运行的工作负载执行故障注入实验。

简单来说，它的作用就是让您**安全、可控、自动化地**破坏您的应用，以此来测试和提高应用的**弹性 (Resilience)**、**性能**和**可靠性**。

### 核心概念：混沌工程自动化

AWS FIS 的设计目标是让用户能够轻松地在生产或准生产环境中进行混沌实验，而无需编写复杂的脚本或自建工具。它提供了预配置的工具来模拟真实世界的故障。

#### 1. 实验模板 (Experiment Template)

这是 AWS FIS 的核心配置单元。您在模板中定义了整个实验的蓝图，包括：

- **操作 (Actions):** 定义要执行的破坏性活动。
- **目标 (Targets):** 定义操作要作用于的 AWS 资源。
- **停止条件 (Stop Conditions):** 定义在实验期间，如果系统的某些指标（例如 CloudWatch 告警）达到临界点，实验应该立即停止。这是确保实验安全的关键。

#### 2. 操作 (Actions)

操作是 AWS FIS 在实验期间对 AWS 资源执行的活动。AWS FIS 提供了针对不同 AWS 服务预配置的操作，例如：

| AWS 服务 | 常见操作示例 | 模拟的故障类型 |
| :--- | :--- | :--- |
| **Amazon EC2** | 停止 (Stop) 或终止 (Terminate) 实例 | 硬件故障、操作系统崩溃 |
| **Amazon ECS/EKS** | 停止 ECS 任务，或杀死 EKS Pod | 容器或 Pod 级别的故障 |
| **Amazon RDS** | 重启数据库实例，模拟 I/O 延迟 | 数据库连接中断、性能下降 |
| **Networking** | 注入 API 延迟，限制网络带宽 | 网络拥塞、依赖服务响应慢 |

操作可以按**顺序运行**，也可以**同时运行（并行）**，以模拟复杂的故障场景。

#### 3. 目标 (Targets)

目标是您选择让操作作用的一个或多个 AWS 资源。您可以通过以下方式定义目标：

- 选择特定的资源 ID。
- 根据标签 (Tags) 或状态选择一组资源。例如，选择所有带有 `env: production` 标签的 EC2 实例。

#### 4. 安全杆 (Safety Lever)

AWS FIS 包含一个安全机制，称为**安全杆 (Safety Lever)**。这是一个账户和区域级别的控制开关：

- **作用：** 如果激活，安全杆会立即停止所有正在进行的 FIS 实验，并阻止新的实验开始。
- **目的：** 作为应对紧急情况的最后防线，确保在应用程序健康状况出现意外警报时，可以迅速停止所有破坏性活动。

### AWS FIS 的价值

使用 AWS FIS 的目的不是为了让应用崩溃，而是为了：

1. **验证弹性：** 确认应用在关键组件失效时，是否能按预期自动恢复、切换或降级服务。
2. **发现弱点：** 找出系统中隐藏的、只在压力或故障下才会暴露的缺陷（例如，未捕获的超时、不正确的重试逻辑）。
3. **验证监控和告警：** 确认您的监控系统能否在故障发生时，及时、准确地发出告警。
4. **提高团队信心：** 通过定期进行混沌实验，提高运维团队和开发团队对系统在极端情况下的行为的理解和信心。

简而言之，AWS FIS 是一个**用于主动构建和验证高弹性系统的工具**。

---

## [Chaos Mesh](https://chaos-mesh.org/docs/)

是一个专为 **Kubernetes (K8s)** 设计的开源、云原生**混沌工程 (Chaos Engineering)** 平台。

它提供了一套全面且易于使用的工具集，允许您在 Kubernetes 集群环境中安全、可控地注入各种故障，以测试系统的弹性。

### Chaos Mesh 的核心定位

Chaos Mesh 弥补了 Kubernetes 自身在故障注入能力上的不足。它将混沌工程实验所需的所有复杂操作（如网络延迟、Pod 压力、系统调用错误）抽象为 Kubernetes 的 API 对象。

**简单来说，Chaos Mesh 的工作方式就是：** 您通过定义一个 YAML 文件（Chaos 对象），告诉 Kubernetes 您的破坏意图，然后 Chaos Mesh 的控制器会执行这个破坏操作。

### 核心组件与工作原理

Chaos Mesh 主要由以下几个核心组件构成：

#### 1. Chaos Controller Manager (混沌控制器管理器)

- **作用：** 这是 Chaos Mesh 的大脑。它作为 Kubernetes 中的一个控制器 (Controller) 运行，负责监听所有自定义的混沌资源对象（如 `NetworkChaos`, `PodChaos`）。
- **机制：** 当您创建或更新一个 Chaos 对象时，Controller Manager 负责解析您的意图，并通知 Agent 执行相应的故障注入。

#### 2. Chaos Daemon (混沌守护进程)

- **作用：** 运行在集群的每个节点 (Node) 上，以 `DaemonSet` 的形式部署。
- **机制：** Daemon 拥有较高的权限，负责在 Pod 级别或主机级别执行实际的破坏操作（例如，利用 `cgroup` 限制资源，或使用 `iptables` 注入网络延迟）。

#### 3. Chaos Dashboard (混沌仪表盘)

- **作用：** 提供一个 Web 界面，用于管理、监控和可视化混沌实验。
- **优势：** 即使不熟悉 `kubectl` 或 YAML，用户也能通过图形界面定义复杂的实验。

### Chaos Mesh 提供的故障类型

Chaos Mesh 提供了多种故障类型，让您可以针对 K8s 系统的不同方面进行测试：

| 故障类型 (Chaos Kind) | 作用目标 | 模拟的故障场景 |
| :--- | :--- | :--- |
| **`PodChaos`** | 瞄准 Pod 或容器 | 随机杀掉 Pod、暂停容器、导致容器 OOM (内存溢出)。 |
| **`NetworkChaos`** | 瞄准 Pod 间的网络 | 注入网络延迟 (latency)、网络丢包 (loss)、网络抖动 (jitter)、网络分区。 |
| **`IOChaos`** | 瞄准文件系统 I/O | 模拟文件 I/O 延迟或 I/O 错误（例如，数据库操作变慢或失败）。 |
| **`KernelChaos`** | 瞄准内核 | 导致内核 Panic，模拟主机系统故障。 |
| **`TimeChaos`** | 瞄准系统时间 | 调整容器内系统时间，测试依赖时间的服务（如证书过期）。 |
| **`StressChaos`** | 瞄准资源压力 | 持续占用 CPU 或内存，模拟高负载情况。 |

### 使用 Chaos Mesh 的优势

1. **云原生集成：** 它是完全基于 Kubernetes 原生 API (CRD) 构建的，与其他 K8s 工具链无缝集成。
2. **细粒度控制：** 可以通过 **Selector (选择器)** 精确指定故障作用的目标 Pod、节点或特定的应用实例。
3. **安全和可观测性：** 提供了强大的**恢复机制**和**停止条件 (Stop Conditions)**，确保实验不会失控，并且可以集成 Prometheus 进行实时监控。
4. **易于扩展：** 其架构允许社区和用户轻松扩展和添加新的故障类型。

Chaos Mesh 是目前在 Kubernetes 混沌工程领域最流行和功能最强大的工具之一，是实施高可靠性策略的关键组件

---

## LitmusChaos

是另一个专为 **Kubernetes (K8s)** 设计的开源混沌工程平台。它与 Chaos Mesh 一样，旨在帮助开发者和 SRE 团队在 K8s 环境中安全、有组织地运行混沌实验，从而提高应用程序的弹性。

LitmusChaos 的设计哲学是**基于工作流 (Workflow)** 和**可插拔性 (Pluggability)**，它特别强调将混沌实验作为 CI/CD 流水线的一部分。

### LitmusChaos 的核心概念

#### 1. Chaos Experiments (混沌实验)

LitmusChaos 的故障注入逻辑被封装在独立的、可重用的 **Chaos Experiment** 单元中。这些实验通常是以 Helm chart 或 YAML 文件的形式提供，可以像安装普通应用一样部署和管理。

#### 2. Chaos Operator (混沌操作器)

这是 Litmus 的核心控制器。它负责监听和协调实验，确保实验按照预定义的规范执行。当用户创建或更新实验资源时，Operator 负责：

- **准备 (Pre-Chaos):** 检查目标环境是否准备好。
- **注入 (Inject):** 启动实际的故障注入。
- **验证 (Post-Chaos):** 验证故障是否被成功注入和移除。

#### 3. ChaosCenter (控制面板)

ChaosCenter 是一个集中的 Web UI，用于管理集群、设计实验、编排混沌工作流以及查看实验结果。它提供了：

- **集中管理：** 管理多个 K8s 集群上的混沌实验。
- **工作流编排：** 允许用户将多个混沌实验串联起来，形成复杂的测试场景。
- **报告和分析：** 提供详细的实验报告和弹性得分 (Resilience Score)。

### 核心工作流程：Chaos Workflows

LitmusChaos 最强大的特性是它的 **Chaos Workflows**。它利用 Kubernetes 原生的 **Argo Workflows** 引擎来编排一系列复杂的混沌和非混沌步骤。

一个混沌工作流可以包括：

1. **准备阶段 (Pre-Chaos):** 运行健康检查脚本、部署特定的监控工具。
2. **混沌注入 (Chaos Injection):** 运行 Pod 终止、网络延迟等实验。
3. **应用验证 (Application Validation):** 运行业务级测试脚本（例如，检查订单系统是否仍然能够处理交易）。
4. **清理阶段 (Post-Chaos):** 移除故障并清理实验资源。

这种工作流方法允许用户将混沌实验融入到复杂的 CI/CD 流程中，实现**混沌测试即代码 (Chaos as Code)**。 

### LitmusChaos 的主要优势

1. **Workflows 驱动：** 强大的工作流编排能力，允许用户创建高度定制化的故障场景和恢复测试。
2. **丰富的实验库：** 拥有一个庞大的社区驱动的 **Chaos Hub**，提供了针对各种 Kubernetes 资源和云服务（如 AWS、Azure）的预构建实验。
3. **安全和可靠性：** Litmus 强调通过 **Chaos Guard** 机制来确保实验安全，即在实验期间实时监控系统，并在检测到关键指标异常时自动停止实验。
4. **面向开发者：** 实验定义是基于 YAML 的声明式配置，易于集成到 GitOps 和 CI/CD 流程中。

**总结：**

LitmusChaos 是一个成熟的 K8s 混沌工程工具，特别适合需要将混沌实验作为自动化测试和 CI/CD 流程一部分的团队，因为它强大的工作流和编排能力。

---

## GitHub Actions (GHA)

### 1. GHA (GitHub Actions) 的定义

- **定义：** GitHub Actions 是 GitHub 提供的 **持续集成/持续交付 (CI/CD)** 和工作流自动化平台。它允许您在代码仓库中定义一系列自动化任务（称为 **Workflow**），用于构建、测试、部署您的代码。
- **用途：** GitHub Actions 的核心用途是自动化 **流程**，而不是注入故障本身。

### 2. GHA 与混沌工程的关联：Chaos in CI/CD

GHA 本身不是一个混沌工程工具，但它是**将混沌工程集成到 CI/CD 流程中**的关键自动化工具。这种集成被称为 **Chaos in CI/CD**。

#### 工作原理

通过 GHA，您可以实现以下自动化混沌实验流程：

1. **触发 Workflow：** 开发者提交代码或合并拉取请求 (`PR`) 到主分支。
2. **构建和部署：** GHA 首先构建容器镜像，并将其部署到临时的 Staging (预发布) 环境或 Dev 环境。
3. **运行稳定性测试：**
    - GHA **执行一个步骤**，该步骤调用 **混沌工程工具** (如 Chaos Mesh 或 LitmusChaos) 的 CLI 或 API。
    - **注入故障：** 例如，注入 30 秒的网络延迟。
4. **业务指标验证：** 在故障注入期间，GHA 同时运行一套业务级的端到端 (E2E) 测试或检查关键的 **SLOs/稳态假设**。
5. **判断结果：**
    - 如果应用在故障下**保持稳定**，GHA 流程继续，允许部署。
    - 如果应用**失效**（稳态假设被打破），GHA 流程失败，阻止部署，并向开发者提供反馈。
6. **清理：** 移除故障，销毁 Staging 环境。

#### 总结关联

| 角色 | 工具 | 作用 |
| :--- | :--- | :--- |
| **故障注入器** | Chaos Mesh, LitmusChaos | 负责**制造**故障。 |
| **自动化编排器** | **GitHub Actions (GHA)** | 负责**流程化和自动化**故障注入与验证的步骤。 |

### 3. 识别 FaaS 相关的 GHA

在混沌工程社区中，没有一个官方或被广泛认可的“AWS FaaS”或“GCP FaaS”的 GHA。不过，您可能会看到与流行的混沌工程平台相关的 GitHub Actions：

- **LitmusChaos Action:** LitmusChaos 官方或社区提供了一个 GHA，允许用户直接在 Workflow 中调用 LitmusChaos 的 `chaos-runner`，运行预定义的混沌实验。
- **Chaos Mesh Action:** 类似地，也有用于在 GHA 中触发 Chaos Mesh 实验的自定义 Action。

**结论：**

GHA（GitHub Actions）本身不是 Fault as a Service，但它是实现 **Chaos as Code** 和 **Chaos in CI/CD** 的主流自动化引擎。它通过集成专门的混沌工具，自动化了故障注入、验证和清理的全过程。

### GHA + LitmusChaos 流程示例

使用 **GitHub Actions (GHA)** 触发 **LitmusChaos** 实验的简单流程示例。这个示例展示了如何将一个简单的混沌实验集成到您的 CI/CD 流程中。

假设您的目标是：**在部署新代码后，自动杀掉一个关键 Pod，并确认应用能够自愈（即 Pod 自动重启并恢复 `Running` 状态）。**

#### 1\. 场景设置

- **应用：** 一个名为 `my-frontend-deployment` 的 Kubernetes Deployment。
- **混沌工具：** LitmusChaos 已经部署在集群中。

#### 2\. GHA Workflow (`.github/workflows/chaos-test.yaml`)

这个 YAML 文件定义了在代码合并后执行的自动化步骤：

```yaml
name: Chaos Engineering CI Test

on:
  push:
    branches:
      - main

jobs:
  run_chaos_experiment:
    runs-on: ubuntu-latest
    steps:
      - name: Checkout Code
        uses: actions/checkout@v4
      
      # Step 1: 部署或连接到 K8s 集群
      - name: Setup Kubeconfig
        uses: azure/k8s-set-context@v3 
        # 实际操作中，这里会使用 secret 凭证连接您的 K8s 集群
        with:
          method: kubeconfig
          kubeconfig: ${{ secrets.KUBE_CONFIG_DATA }}
          
      # Step 2: 运行混沌实验
      - name: Run Pod Kill Chaos Experiment
        uses: litmuschaos/litmus-action@v2
        id: run_chaos
        with:
          # 指定要运行的实验，这里使用 Pod-Delete 实验
          # (Litmus 从 Chaos Hub 拉取这个实验的定义)
          # 注意：这个实验必须首先在您的 Litmus 环境中可用
          experiment-name: pod-delete
          # 指定目标应用，使用 K8s 标签选择器
          target-service: 'app=my-frontend' 
          # 实验的时长 (秒)
          chaos-duration: 30
          # 检查 Pod 是否在实验期间保持 Running/Ready
          probes: 'app-health-check' 
          
      # Step 3: 检查实验结果
      - name: Check Chaos Result
        if: ${{ failure() }} # 如果上一步 (run_chaos) 失败
        run: |
          echo "Chaos Experiment Failed! The application failed to recover within the duration."
          # 可以在这里添加通知 Slack 或邮件的逻辑
          exit 1
          
      - name: Success Message
        if: ${{ success() }}
        run: echo "Chaos Experiment Succeeded! Application is resilient to Pod failure."
```

#### 流程解释

1. **Workflow 启动：** 当代码推送到 `main` 分支时，GHA 启动。
2. **连接集群：** GHA 通过配置的 Kubeconfig 凭证连接到您的 Kubernetes 集群。
3. **Chaos Action 执行：** `litmus-action` 步骤开始。
      - 它在集群中创建一个 Litmus **ChaosEngine** 和 **ChaosResult** 对象。
      - **注入：** Chaos Operator 收到请求，随机选择带有 `app=my-frontend` 标签的 Pod，并将其杀死。
      - **验证：** 在 30 秒的实验持续时间内，Action 不断检查应用是否通过了预定义的 `probes`（即应用是否健康恢复）。
4. **结果判定：**
      - 如果 Pod 被杀死后，Kubernetes 自动创建了新的 Pod，并且新的 Pod 在 30 秒内恢复健康，则 `litmus-action` **成功**。
      - 如果 Pod 无法恢复（例如，陷入 `CrashLoopBackOff`），则 `litmus-action` **失败**。
5. -**CI/CD 决策：** GHA 根据 `litmus-action` 的成功或失败来决定后续步骤（如是否允许合并或部署到生产环境）。

通过这种方式，您可以在每次代码更改时，自动且非侵入性地测试应用对关键故障的弹性。

---

## AWS FIS (云服务)、Chaos Mesh (K8s) 和 LitmusChaos (K8s) 的比较、分析和综合

这是一个极好的、非常深入的问题，它要求我们从工具选择、云原生环境集成、以及 CI/CD 流程自动化的角度来审视当前的混沌工程生态系统。

### 三大混沌工程平台的比较与分析

| 特性 | AWS Fault Injection Service (FIS) | Chaos Mesh | LitmusChaos |
| :--- | :--- | :--- | :--- |
| **平台类型** | **云服务 (Managed Service)** | **Kubernetes 原生工具** | **Kubernetes 原生工具** |
| **工作目标** | **AWS 资源**（EC2, RDS, VPC, EKS/ECS 等） | **K8s 资源**（Pod, 节点, 容器, 网络） | **K8s 资源**，**可扩展到云资源** |
| **注入机制** | 调用 AWS API | K8s CRD + Chaos Daemon (高权限) | K8s CRD + Chaos Operator/Runner |
| **核心优势** | 深度集成 AWS 生态，**安全停止条件 (Stop Conditions)**，无需安装和维护。 | 故障类型丰富，基于 **CRD**，对 K8s 内部机制的控制细致。 | **Chaos Workflows (基于 Argo)**，强大的编排能力，社区实验库丰富。 |
| **适用范围** | 必须运行在 AWS 上。 | 必须运行在 K8s 上。 | 必须运行在 K8s 上。 |
| **学习曲线** | 低（通过 AWS 控制台操作）。 | 中（主要通过 YAML 配置）。 | 中到高（涉及 Workflows 和 Probes）。 |

### 共同之处与差异点

#### 共同之处 (Commonalities)

1. **目标一致性：** 三者都是为了实现 **混沌工程** 的目标，即主动发现系统的弹性弱点。
2. **声明式配置：** Litmus 和 Chaos Mesh 都是通过 Kubernetes **自定义资源定义 (CRD)** 来声明实验意图，AWS FIS 也是通过 API/模板来声明实验意图。
3. **安全性关注：** 三者都提供或强调 **停止条件 (Stop Conditions)** 或 **Probes** 机制，确保实验不会失控并造成永久性破坏。

#### 主要差异 (Key Differences)

| 平台 | 关注点 | 适用场景 |
| :--- | :--- | :--- |
| **AWS FIS** | **IaaS 层级故障：** 专注于测试应用程序对底层云基础设施（VM、数据库、网络服务）失效的反应。 | **云弹性验证：** 验证应用在 AWS 服务故障（如 RDS 重启、EC2 实例终止）时的自愈能力。 |
| **Chaos Mesh** | **容器运行时故障：** 专注于操作系统内核、容器和网络命名空间级别的低级故障注入。 | **核心容器弹性测试：** 针对 Pod、容器、网络 I/O 压力等，进行深度、细粒度的 K8s 内部机制测试。 |
| **LitmusChaos** | **工作流与业务验证：** 专注于将故障注入与业务验证测试（Probes）串联起来，并作为自动化流程执行。 | **CI/CD 集成与复杂场景：** 需要将混沌实验作为自动化测试的一部分，或需要复杂的串行/并行实验步骤。 |

### 重叠、互补与协同使用

#### 重叠性 (Overlap)

- **LitmusChaos 和 Chaos Mesh** 在 **Pod/Network 级别的故障注入** 方面存在重叠。两者都可以杀死 Pod、注入网络延迟等。
- **AWS FIS (如果作用于 EKS 节点)** 和 K8s 原生工具在 **节点级故障** 上有功能重叠（例如，FIS 可以终止 EC2 节点，K8s 工具也可以通过删除 Node 资源来模拟节点故障）。

#### 互补性 (Complementarity)

这三个工具是高度互补的，可以分层测试系统的弹性：

| 工具 | 测试的层级 | 验证的关键弹性能力 |
| :--- | :--- | :--- |
| **AWS FIS** | **基础设施层** | 验证应用的**跨可用区 (AZ) 容灾**和对**云服务**依赖的鲁棒性。 |
| **Chaos Mesh/Litmus** | **K8s/应用层** | 验证 **K8s 自身调度器、控制器**以及**微服务间通信**的鲁棒性。 |

#### 协同使用示例

1. 使用 **AWS FIS** 终止承载 EKS/ECS 的 **EC2 节点**。
2. 观察 **K8s/ECS** 是否成功将 Pod/任务迁移到其他节点（这是基础设施层面的弹性）。
3. 使用 **LitmusChaos** 或 **Chaos Mesh** 在 **应用 Pod 迁移过程中** 注入 **网络延迟**。
4. 观察应用在 **双重故障** (底层节点故障 + 应用间通信不稳定) 场景下的表现。

### 如何与 GHA 和谐整合？

GHA 是实现“Chaos in CI/CD”的理想载体，它将这三个工具的强大能力编排成自动化流程。

#### GHA 整合流程 (以 LitmusChaos 为例)

1. **GHA 步骤 1 (基础设施故障)：**
    - 使用 AWS CLI Action 或 Terraform/CloudFormation Action，调用 **AWS FIS API** 启动一个实验，例如：终止 Staging 环境中的随机 EC2 实例。
    - **目的：** 验证应用能否在底层基础设施损耗的情况下保持稳定。

2. **GHA 步骤 2 (应用层故障)：**
    - 使用 **LitmusChaos Action** 或 Chaos Mesh CLI Action，在 K8s 集群中启动一个实验，例如：注入 200ms 的网络延迟。
    - **目的：** 验证应用服务间的重试、超时和断路器逻辑是否有效。

3. **GHA 步骤 3 (稳态验证)：**
    - 在两个故障注入期间，运行一系列 E2E 测试或指标检查。
    - 如果测试失败（稳态假设被打破），GHA 流程立即停止，**并触发 AWS FIS 或 Litmus 的停止机制**。

**结论：**

这三个平台不应被视为相互排斥的竞争者。一个成熟的云原生组织会根据目标（底层云服务、K8s 核心机制、复杂业务流程）的不同，将 **AWS FIS**、**Chaos Mesh** 和 **LitmusChaos** **分层组合**，并由 **GitHub Actions (GHA)** 等自动化工具进行编排，实现全面的弹性验证。 

---

## 分层自动化混沌验证系统的最佳实践

将 AWS FIS、Chaos Mesh 和 LitmusChaos 分层组合，并由 GitHub Actions (GHA) 编排，能够提供最全面、最具代表性的弹性测试。

以下是实现这种分层协同和自动化编排的详细策略和步骤。

### 整体策略：分层测试模型

我们的目标是模拟真实世界中从底层基础设施到应用逻辑的所有潜在故障，并确保应用在每个层级都能保持**稳态 (Steady State)**。

| 混沌工具 | 目标层级 | 测试目的 |
| :--- | :--- | :--- |
| **AWS FIS** | **L1: 基础设施层 (IaaS)** | 验证应用对 **云服务**、**计算节点**、**网络互联** 失效的容忍能力。 |
| **Chaos Mesh** | **L2: K8s/内核层** | 验证应用对 **容器运行时、OS 资源限制、网络命名空间** 故障的鲁棒性。 |
| **LitmusChaos** | **L3: 应用/业务流程层** | 验证应用的 **业务逻辑、恢复探针 (Probes) 和复杂的串行/并行** 故障场景。 |
| **GitHub Actions (GHA)** | **编排/自动化层** | 串联所有工具，在 CI/CD 流程中自动化执行实验、验证假设和清理。 |

### 分层组合与编排的详细步骤

我们将以一个典型的 CI/CD 流程为例，演示 GHA 如何依次触发不同工具的实验。

#### Step 0: 前置条件与假设定义

- **稳态假设 (Steady State):** 定义本次实验中业务需要保持稳定的指标（例如：API 成功率 \> 99.9%，交易处理时间 \< 500ms）。
- **工具部署：** LitmusChaos 或 Chaos Mesh 部署在 EKS/ECS 集群中。AWS FIS 权限配置到位。

#### Step 1: L1 基础设施层故障注入 (AWS FIS)

**目标：** 测试应用是否能应对底层计算资源的消失。

1. **GHA Action:** 使用 AWS CLI Action 或自定义的 AWS FIS Action。
2. **操作：** 调用 AWS FIS API，启动一个实验模板。
      - **故障内容：** 随机终止 EKS 节点池中 25% 的 **EC2 实例**。
      - **GHA 动作：** 启动实验，并等待预设的故障注入时间（例如 60 秒），然后自动停止。
3. **结果验证：** 在 FIS 实验期间，**同时**运行业务测试脚本，检查稳态指标是否被打破。

#### Step 2: L2 K8s/内核层故障注入 (Chaos Mesh)

**目标：** 测试应用对容器内部资源争用或网络细微故障的容忍度。

1. **GHA Action:** 使用 `kubectl` CLI Action 或 Chaos Mesh 专用 Action。
2. **操作：** 部署一个 `NetworkChaos` 或 `StressChaos` YAML 文件。
      - **故障内容：** 针对目标 Pod，注入 **300ms 的网络延迟**，并持续占用 **CPU 资源 80%**。
      - **GHA 动作：** 使用 `kubectl apply` 部署 `Chaos` 对象，并等待持续时间。
3. **结果验证：** 在故障期间，测试应用是否能正确使用 **断路器 (Circuit Breakers)** 和 **重试机制 (Retries)** 来优雅降级。

#### Step 3: L3 应用/业务流程故障注入 (LitmusChaos)

**目标：** 测试复杂的多步骤恢复流程以及业务探针。Litmus 的 Workflow 能力在这里优势明显。

1. **GHA Action:** 使用 **LitmusChaos Action**。
2. **操作：** 启动一个 **Chaos Workflow**。
      - **步骤 1 (混沌注入):** 杀死处理支付的关键 Pod (`pod-delete` 实验)。
      - **步骤 2 (自定义探针):** 运行 Litmus 的 **HTTP Probes**，持续检查 Payment API 的成功率。
      - **GHA 动作：** 运行 Litmus Workflow，并等待其返回最终的 **弹性得分 (Resilience Score)**。
3. **结果验证：** Litmus Action 会将弹性得分返回给 GHA。如果得分低于阈值，则整个 GHA 流程失败。

### 结合 GHA 的自动化编排优势

**GHA 在此流程中扮演“指挥家”的角色，提供了以下关键能力：**

1. **序列化执行 (Sequential Execution):** 确保 L1 实验完成后，才开始 L2 实验，防止实验间互相干扰。
2. **环境配置 (Environment Setup):** 负责配置 Kubeconfig、AWS 凭证和必要的环境变量。
3. **失败即失败 (Fail Fast):** 利用 GHA 的 `if: ${{ failure() }}` 逻辑，一旦任何一步（如应用健康检查）失败，立即终止整个 Workflow。
4. **安全停止 (Safety Halt):** 在每一步的末尾或通过 `post` 步骤，确保 **FIS 实验已终止**、**Chaos Mesh CRD 已删除**，并且 **Litmus ChaosEngine 已清理**。

#### GHA 中的关键逻辑示例（伪代码）

```yaml
jobs:
  chaos_validation:
    steps:
      # Step 1: 运行 AWS FIS 故障注入
      - name: Run FIS Node Termination
        # ... 调用 AWS FIS API ...

      # Step 2: 验证业务指标 (稳态假设)
      - name: Validate Steady State
        run: |
          ./run-load-test.sh & # 启动负载测试
          sleep 60s # 等待故障影响
          if [ $(./get-error-rate.sh) -gt 0.01 ]; then
            exit 1 # 稳态被打破，流程失败
          fi
          
      # Step 3: 运行 LitmusChaos Workflows
      - name: Run Litmus Chaos Workflow
        uses: litmuschaos/litmus-action@v2
        # ... 启动 L3 实验 ...

      # Step 4: 清理所有混沌资源（防止影响后续构建）
      - name: Cleanup Chaos Resources
        if: always() # 无论成功失败，都运行清理
        run: |
          kubectl delete chaosengine --all || true
          # ... 调用 FIS 停止机制 ...
```

通过这种分层和自动化，您的团队可以从根本上提高系统的弹性，将混沌工程从手动、临时活动转变为持续的、流程化的 **弹性测试管道**。

---

## [AWS Fault Injection Service (AWS FIS)](https://docs.aws.amazon.com/fis/latest/userguide/what-is.html)

AWS Fault Injection Service (AWS FIS) is a managed service that enables you to perform fault injection experiments on your AWS workloads. These experiments stress an application by creating disruptive events so that you can observe how your application responds. You can then use this information to improve the performance and resiliency of your applications so that they behave as expected.

AWS FIS provides templates that generate disruptions, and the controls and guardrails that you need to run experiments in production, such as automatically rolling back or stopping the experiment if specific conditions are met.

To use AWS FIS, you run experiments on your AWS resources to test your theory of how an application or system will perform under fault conditions.

- An **experiment template** is the blueprint of your experiment. It contains the actions, targets, and stop conditions for the experiment.
- An **action** is an activity that AWS FIS performs on an AWS resource during an experiment. AWS FIS provides a set of pre-configured actions based on the type of AWS resource. Each action runs for a specified duration during an experiment, or until you stop the experiment. Actions can run sequentially or simultaneously (in parallel).
- A **target** is one or more AWS resources on which AWS FIS performs an action during an experiment.
- A **stop condition** is a mechanism to stop an experiment if it reaches a threshold that you define as an Amazon CloudWatch alarm.
- A **experiment role** is an IAM role that grants AWS FIS the permissions required so that it can run experiments on your behalf.
- A **experiment report configuration** to enable experiment report.
- A **experiment options**: options for the experiment template.

Your account has quotas related to AWS FIS, and here is a quota on the number of actions per experiment template. 
  
With AWS FIS, you run experiments on your AWS resources to test your theory of how an application or system will perform under fault conditions.

### Planning AWS FIS Experiments

**Fault injection** is the process of stressing an application in testing or production environments by creating disruptive events, such as server outages or API throttling. From observing how the system responds, you can then implement improvements. When you run experiments on your system, it can help you to **identify systemic weaknesses in a controlled manner**, before those weaknesses affect the customers who depend on your system. Then you can **proactively** address the issues to help prevent unpredictable outcomes.

#### Basic principles and guidelines

1. **Identify the target deployment for the experiment** — Start by identifying the target deployment. 
2. **Review the application architecture** — must ensure that you have identified all of the application components, dependencies, and recovery procedures for each component.
3. **Define steady-state behavior** — Define the steady-state behavior of your system in terms of important technical and business metrics, such as latency, CPU load, failed sign-ins per minute, number of retries, or page load speed.
4. **Form a hypothesis** — Form a hypothesis of how you expect the system behavior to change during the experiment. A hypothesis definition follows this format: If *fault injection action* is performed, the *business or technical metric impact* should not exceed *value*. After the experiment is completed, you evaluate whether the application resiliency aligns with your business and technical expectations.

Guidelines:

- Always start experimenting with AWS FIS in a test environment. Never start with a production environment.
- Build your team’s confidence in your application resilience by starting with small, simple experiments.
- Fault injection can cause real issues. Proceed with caution and make sure that your first fault injections are on test instances so that no customers are affected.
- Fault injection is meant to be implemented in a controlled environment with well-planned experiments.
- strongly recommend that you have an excellent monitoring and alerting program in place before you begin.

#### Experiment Planning Guidelines

1. **Review outage history** — Review the previous outages and events for your system. This can help you to build up a picture of the overall health and resiliency of your system.
2. **Identify services with the largest impact** — Review your services and identify the ones that have *the biggest impact on your end users or customers* if they go down or do not function correctly.
3. **Identify the target system** — The target system is the system on which you will run experiments.
4. **Consult with your team** — Ask what they are worried about. You can form a hypothesis to prove or disprove their concerns. You can also ask your team what they are not worried about. This question can reveal two common fallacies: the sunk cost fallacy and the confirmation bias fallacy. Forming a hypothesis based on your team’s answers can help provide more information about the reality of your system’s state.
5. **Review your application architecture** — Conduct a review of your system or application and ensure that you have identified all of the application components, dependencies, and recovery procedures for every component.
6. **Identify the applicable metrics** — Can use these metrics to determine the baseline or "steady state" when your application is performing optimally. Then, you can monitor these metrics during or after the experiment to determine the impact.
7. **Define an acceptable performance threshold for your system** — Identify the metric that represents an acceptable, steady state for your system. You will use this metric to create one or more CloudWatch alarms that represent a stop condition for your experiment. If the alarm is triggered, the experiment is automatically stopped.

---

## AWS FIS（Fault Injection Service）的 YAML

普通的 Kubernetes YAML（如 Pod、Deployment）是**状态声明**，而 AWS FIS（Fault Injection Service，即你提到的 FIT）的 YAML 是**实验方案**。

K8s YAML 是在描述**我要这台机器长什么样**，而 AWS FIS YAML 是在描述**我要在什么时候、对谁、做一个什么样的破坏动作**。

### AWS FIS YAML 的组织逻辑：三位一体

AWS FIS 的配置文件（通常称为 Experiment Template）是按照“动作流水线”来组织的。它的核心逻辑可以概括为：**对谁做 (Targets) -> 做什么 (Actions) -> 什么时候停 (Stop Conditions)**。

#### 1. Targets (目标：对谁做？)

这部分定义了故障注入的对象。它不像 K8s 只是指定一个名字，它通常使用 **Tags（标签）** 或 **Filters（过滤器）** 来动态筛选资源。

- *比如：* “选中所有标签为 `env:prod` 且处于 `running` 状态的 EC2 实例。”

#### 2. Actions (动作：做什么？)

这是你看到的“最陌生”的部分，也是 `run` 关键字出现的地方。

- AWS FIS 并不总是能直接通过 API 搞坏系统，有时它需要进入系统内部。
- **为什么有 Shell 脚本？** 当你需要模拟“CPU 飙升”、“磁盘占满”或“修改网络配置”时，FIS 会通过 **AWS SSM (Systems Manager)** 在目标机器上运行一段 Linux 命令。这就是你看到的类似 Shell 的内容。

#### 3. Stop Conditions (止损：什么时候停？)

这是混沌工程的“保险丝”。

- 通常关联一个 **CloudWatch Alarm**。如果实验过程中系统的错误率超过 5%，FIS 会自动终止实验并尝试恢复，防止真的把生产环境搞瘫痪。

### 一个具体的 AWS FIS YAML 例子

假设我们要给一组 EC2 实例注入一个“CPU 压力测试”故障。这个 YAML 看起来像这样（为了易读，简化了部分格式）：

```yaml
description: "模拟 CPU 满载实验"
# 1. 目标：选中带有特定标签的 EC2
targets:
  MyTestInstances:
    resourceType: "aws:ec2:instance"
    resourceTags:
      "ChaosReady": "true"
    selectionMode: "ALL" # 选中所有符合条件的

# 2. 动作：运行一段 Shell 脚本来消耗 CPU
actions:
  CPUStress:
    actionId: "aws:ssm:send-command" # 使用 SSM 运行命令
    parameters:
      duration: "PT2M" # 持续 2 分钟
      # 这里的 documentContent 就是你看到的类似 Shell 的部分
      documentContent: |
        {
          "mainSteps": [
            {
              "action": "aws:runShellScript",
              "name": "runCPUStress",
              "inputs": {
                "runCommand": [
                  "sudo apt-get update",
                  "sudo apt-get install -y stress-ng",
                  "stress-ng --cpu 4 --timeout 120s" 
                ]
              }
            }
          ]
        }
    targets:
      Instances: MyTestInstances

# 3. 止损：如果错误率报警，立即停止
stopConditions:
  - source: "none" # 练习时可设为 none，生产环境需设为 CloudWatch Alarm ARN

```

#### 为什么看起来复杂？

1. **嵌套多：** 它嵌套了 AWS 其他服务的协议（比如上面例子里的 SSM Document 格式）。
2. **权限复杂：** FIS 需要代表你执行命令，所以 YAML 里经常会涉及各种 IAM Role 的引用。
3. **流程性：** 它有 `startAfter` 等关键字，可以定义“先断网，再杀进程”这种先后顺序。

### 学习参考资料

如果你想深入理解这种“奇怪”的 YAML，可以参考以下资源：

1. **AWS FIS 用户指南：** 搜索 [AWS FIS Actions Reference](https://docs.aws.amazon.com/fis/latest/userguide/fis-actions-reference.html)，这里列出了所有可用的“破坏动作”。
2. **SSM Documents 语法：** 因为很多 `run` 脚本是基于 SSM 的，理解 [AWS Systems Manager Documents](https://docs.aws.amazon.com/systems-manager/latest/userguide/sysman-ssm-docs.html) 的格式对理解 FIT YAML 至关重要。
3. **混沌工程原则：** 访问 [Principles of Chaos](https://principlesofchaos.org/)，了解为什么要这么组织实验（稳态 -> 假设 -> 注入 -> 验证）。

---

## AWS SSM（Systems Manager）文档

**在 AWS SSM（Systems Manager）文档中，复杂的逻辑（如 `if`、`for` 循环）通常不是 SSM 本身的语法，而是嵌入在 SSM 中的 Shell 脚本语法。**

简单来说，SSM 文档就像是一个“信封”，里面的 `runCommand` 是一封用 **Bash**（Linux）或 **PowerShell**（Windows）写的“信”。

### SSM 文档的基本语法结构

SSM 文档通常使用 YAML 格式，其核心结构如下：

```yaml
schemaVersion: '2.2' # 文档版本
description: "描述这个文档做什么"
parameters: # (可选) 定义变量，可以在脚本中引用
  Action:
    type: String
    default: "Install"
mainSteps: # 核心步骤
  - action: aws:runShellScript # 动作类型：执行 Shell 脚本
    name: runMyScript # 步骤名称
    inputs:
      runCommand: # 这里就是你看到的“代码”部分
        - |
          # 这下面其实是标准的 Linux Shell 语法！
          if [ "{{Action}}" == "Install" ]; then
            echo "开始安装..."
            sudo apt-get install -y nginx
          else
            echo "跳过安装。"
          fi

```

### 为什么你会看到 `if` 语句？

在 AWS FIS（故障注入）的场景下，`if` 语句通常出现在 `runCommand` 列表里。这主要有三个原因：

1. **环境检查：** 在注入故障前，先判断目标路径是否存在。
   - `if [ -d "/mnt/data" ]; then ...`

2. **幂等性（Idempotency）：** 确保脚本多次运行不会报错。
   - `if ! command -v stress-ng &> /dev/null; then sudo apt install stress-ng; fi`（如果没装这个工具，就装一下）。

3. **状态清理：** 判断故障是否已经存在，如果存在先清理再重新注入。

### SSM 原生的“逻辑控制”语句

虽然脚本内部用的是 Bash，但 SSM 文档本身也提供了一些**原生的逻辑控制键**，用来决定步骤（Steps）之间的流转：

#### 1. `precondition` (预设条件)

决定该步骤是否执行。如果条件不满足，该步骤会被跳过。

```yaml
- action: aws:runShellScript
  name: testStep
  precondition:
    StringEquals:
      - "{{ platformType }}"
      - "Linux"

```

#### 2. `nextStep` 和 `finallyStep` (分支跳转)

这类似于编程里的 `goto` 或 `switch`。你可以根据上一步的结果跳转到不同的步骤。

- `onFailure`: 如果这一步失败了，下一步去哪（比如去执行“清理”步骤）。
- `onSuccess`: 成功了去哪。

#### 3. `timeoutSeconds` (超时控制)

在故障注入中非常重要。如果脚本跑太久没反应，SSM 会强行终止它。

### 总结：如何快速读懂它？

当你再次看到那种复杂的 YAML 时，请尝试**分两步拆解**：

- **第一步（看外壳）：** 找 `action: aws:runShellScript`。这告诉你接下来的内容是发给 Linux 机器执行的指令。
- **第二步（读内核）：** 把 `runCommand` 下面的内容当成一个 **.sh 脚本**来读。
  - `{{ ... }}`：这是 SSM 的变量占位符。
  - `if [ ... ]; then ... fi`：这是标准的 Linux 判断语句。

#### 常用参考资料

- **AWS 官方文档：** [SSM 插件语法参考](https://docs.aws.amazon.com/systems-manager/latest/userguide/ssm-plugins.html)（涵盖了 `aws:runShellScript` 等所有动作）。
- **SSM 文档模式：** [SSM Document Schema](https://docs.aws.amazon.com/systems-manager/latest/userguide/document-schemas-features.html)。

---

## Bash in YAML

Shell（主要是 Bash）就像是在**和电脑下达一连串简短的指令**。在 AWS FIS 或 SSM 的 YAML 中，Shell 脚本通常扮演“现场特工”的角色：去检查环境、安装工具、或者搞点破坏。

能够**看懂**大部分 SSM 脚本的核心语法。

### 1. 最核心的逻辑：`if` 语句（判断）

你在 YAML 中看到的 `if` 语句，其实就是电脑的“选择题”。它的结构很固定，但长得有点怪：

```bash
if [ 这里的条件为真 ]; then
    # 做这件事
else
    # 否则做那件事
fi  # fi 就是 if 倒过来写，代表判断结束

```

#### 常见条件判断符号

在 `[` `]` 括号里，你会看到这些缩写，它们是理解逻辑的关键：

- **`-d` (directory):** “这是一个目录吗？”
  - `if [ -d "/var/log" ]; then ...`
- **`-f` (file):** “这是一个文件吗？”
  - `if [ -f "/etc/config" ]; then ...`
- **`-z` (zero):** “这个字符串是空的吗？”
- **`==` 或 `-eq`:** “两者相等吗？”
- **`!=` 或 `-ne`:** “两者不相等吗？”

### 2. 变量：存储信息

Shell 脚本中不需要定义类型，直接赋值即可。但在**使用**变量时，前面必须加一个 **`$`** 符号。

```bash
TARGET_PATH="/tmp/test"        # 赋值（注意等号两边不能有空格！）
echo "正在检查 $TARGET_PATH"    # 使用变量

```

### 3. 常见命令（你在 FIT 脚本中常看到的）

在 SSM 的 `runCommand` 里，你经常会看到这几个“常客”：

- **`sudo`:** 以管理员（最高权限）身份运行。
- **`apt-get` / `yum`:** 安装软件的工具（比如安装用来制造故障的 `stress-ng`）。
- **`grep`:** 搜索关键字。
- **`> /dev/null 2>&1`:** 这是个“黑洞”，意思是不管执行成功还是失败，都不要把信息打印到屏幕上。
- **`echo`:** 在屏幕上打印一句话。

### 4. 组合指令：`&&` 和 `||`

这是 Shell 里的短路逻辑，非常高效：

- **`A && B`:** “只有 A 成功了，才去执行 B”。（相当于：执行并继续）
- **`A || B`:** “如果 A 失败了，就去执行 B”。（相当于：备选方案）

### 5. 实战翻译：带你读一段 FIT 脚本

假设你在 YAML 的 `runCommand` 里看到这一段：

```bash
if ! command -v stress-ng &> /dev/null; then
  sudo apt-get update && sudo apt-get install -y stress-ng
fi
```

我们来把它翻译成人话

1. **`command -v stress-ng`**: 检查系统里有没有 `stress-ng` 这个工具。
2. **`! ... &> /dev/null`**: “如果不存这个工具（并且把报错信息隐藏起来）”。
3. **`then ... fi`**: 那么：
4. **`sudo apt-get update && ...`**: 先更新软件列表，**如果更新成功了**，再安装 `stress-ng`。

### 快速看懂的三个窍门

1. **找关键字：** 先看有没有 `if`, `then`, `else`, `fi`。这决定了代码的整体走向。
2. **找 $ 符号：** 凡是带 `$\` 的都是变量，通常代表路径、IP 或配置名。
3. **忽略长命令：** 像 `stress-ng --cpu 4 --timeout 120s` 这种，你只需要知道它在执行具体的“破坏任务”，具体的参数（`--cpu` 等）如果不记得，可以随时查字典。

---

## AWS FIS/SSM 文档中经常出现的几类“模版化”的 Shell 脚本

以下是故障注入脚本中最常见的四个“套路”：

### 模式一：环境自愈与工具安装 (The "Check-and-Install" Pattern)

因为云服务器可能是新启动的，上面不一定有故障模拟工具（如 `stress-ng`）。脚本的第一步通常是“缺啥补啥”。

```bash
# 如果没有找到这个命令
if ! command -v stress-ng &> /dev/null; then
  # 那就尝试安装它
  if [ -f /etc/debian_version ]; then
    sudo apt-get update && sudo apt-get install -y stress-ng
  elif [ -f /etc/redhat-release ]; then
    sudo yum install -y stress-ng
  fi
fi

```

- **关键词：** `command -v` (检查命令是否存在), `apt-get` / `yum` (安装工具)。
- **目的：** 确保后面的破坏指令能跑得通。

### 模式二：带保护的破坏指令 (The "Safe Attack" Pattern)

直接杀进程可能会导致机器死机无法恢复，所以脚本通常会带有**超时**或**后台运行**逻辑。

```bash
# 启动 CPU 压力测试，持续 60 秒后自动停止
stress-ng --cpu 4 --timeout 60s &

# 记录下这个进程的 ID，方便后续万一要手动清理
ATTACK_PID=$!
echo "故障进程 ID 为: $ATTACK_PID"

```

- **关键词：** `&` (让命令在后台跑，不阻塞脚本), `$!` (获取最后一个后台进程的 ID)。
- **目的：** 确保故障是受控的，不会让脚本卡死。

### 模式三：状态检查与回滚 (The "Validation" Pattern)

有些脚本会包含一个判断逻辑，确认故障是否真的生效了，如果没有生效则报错退出。

```bash
# 检查 80 端口是否还在监听
if ss -tuln | grep -q ":80 "; then
  echo "服务依然在线，故障注入失败！"
  exit 1  # 告诉系统，这一步执行失败了
else
  echo "服务已下线，符合实验预期。"
fi

```

- **关键词：** `grep -q` (安静地搜索关键词), `exit 1` (报错并终止实验)。
- **目的：** 验证实验的有效性。

### 模式四：变量替换 (The "Placeholder" Pattern)

这是最让初学者困惑的地方。你会看到很多大括号 `{{ ... }}`。

```bash
# 在 YAML 中看起来可能是这样：
# runCommand: ["sudo kill -9 {{TargetProcessId}}"]

# 实际上在执行时，SSM 会把它变成：
sudo kill -9 1234

```

- **注意：** `{{ ... }}` 不是 Shell 的语法，而是 **SSM 的变量注入**。看到它，你就把它当成一个“填空题”，实际执行时会被换成具体的值。

### 总结：看懂脚本的“三板斧”

下次当你打开公司的 YAML 看到 `run` 字段时，请按顺序寻找这三个标志：

1. **`#!` 或者 `sudo` 开头：** 它是脚本的开始。
2. **`if ... fi` 块：** 它在做决定（装软件？查环境？报错？）。
3. **具体的工具名：** 看到 `kill`, `stress-ng`, `tc` (控制网络), `rm` (删除文件)，你就知道它具体在“干什么坏事”了。

---