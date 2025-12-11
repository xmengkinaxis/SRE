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
  - [AWS Fault Injection Service (AWS FIS)](#aws-fault-injection-service-aws-fis)
    - [Planning AWS FIS Experiments](#planning-aws-fis-experiments)
      - [Basic principles and guidelines](#basic-principles-and-guidelines)
      - [Experiment Planning Guidelines](#experiment-planning-guidelines)


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

## [AWS Fault Injection Service (AWS FIS)](https://docs.aws.amazon.com/fis/latest/userguide/what-is.html)

AWS Fault Injection Service (AWS FIS) is a managed service that enables you to perform fault injection experiments on your AWS workloads. These experiments stress an application by creating disruptive events so that you can observe how your application responds. You can then use this information to improve the performance and resiliency of your applications so that they behave as expected.

AWS FIS provides templates that generate disruptions, and the controls and guardrails that you need to run experiments in production, such as automatically rolling back or stopping the experiment if specific conditions are met.

To use AWS FIS, you run experiments on your AWS resources to test your theory of how an application or system will perform under fault conditions.

- An **experiment template** is the blueprint of your experiment. It contains the actions, targets, and stop conditions for the experiment.
- An **action** is an activity that AWS FIS performs on an AWS resource during an experiment. AWS FIS provides a set of pre-configured actions based on the type of AWS resource. Each action runs for a specified duration during an experiment, or until you stop the experiment. Actions can run sequentially or simultaneously (in parallel).
- A **target** is one or more AWS resources on which AWS FIS performs an action during an experiment.
- A **stop condition** is a mechanism to stop an experiment if it reaches a threshold that you define as an Amazon CloudWatch alarm.
  
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