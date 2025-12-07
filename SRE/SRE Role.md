# SRE role

## Definition

Site Reliability Engineering (SRE)

SRE use software engineering approaches to solve operational problems. Their goal is to create ultra-scalable and highly reliable software systems. 

Reliability: Ability of a system, product, or service to perform its intended function consistently and dependably under a given set of conditions and over a specific period of time. (Users can trust the system or service)

- Availability: available and accessible to users without unexpected downtime or outages
- Consistency: delivery same result when performing a specific task or operation
- Durability: withstand extended periods of user or operations without degradation or failure
- Fault Tolerance: Resilient to faults or failures and can recovery gracefully from errors
- Predictability: User can predict how the system will behave as expected or not

SRE is the core to a business success.

SRE is to enhance the reliability and scalability of software system, leading to better operational outcomes and overall efficiency. 

Focus on:

- Reliability
- Availability
- Performance

Objective: balance between reliability and development velocity (innovation)

Vs DevOps (similarity and different)

Objective: improve overall efficiency and effectiveness of software development and deployment process. (Release Fast)

Daily works ( by percentage??)

- capacity planning
- incident response
- DR ??? planning
- performance optimization
- system automation
- on-call

Vs SDE:
SDE: how software was designed to run.
SRE: how software actually run. Bridge the gap between what we want to happen and what actually happens. constantly feed the data on how customer use the software back to SDE.


SRE should be allocated 50% of their time in operations, e.g. solving customer issues, and the remaining 50% engineering on planning in advanced, e.g. automate everything.

## Technology Stack (sorted from basic to advance, or according cloud native stack)

- Monitoring and Alerting Tools
- Observability (logging); RCA
- Incident Management tools
- Automation and Configuration Management
- Infrastructure as Code (IaC)
- Testing
- Security and Identity Management
- Backup and DR solutions ??? what is DR
- Load Balancer and Proxies
- Containers and orchestration
- Cloud: AWS, Azure, GCP
- Application Deployment

## Practice

- automation; to reduce manual toil and repetitive tasks

## Measurements

- Service Uptime
- SLO??

## Automation

- Infrastructure as Code
- Application Deployment
- Testing (system integration and units)
- Continuous Evaluation; general infrastructure guardrail and standard operations activity
- Product Catalog; create templates and products catalog to enable product as a service

## Resiliency vs Innovation (trade-off)

## Principles

- Availability > Functionality (prioritize)
- Minimizing Downtime (through proactive identification and resolution of potential problems)
- Automate manual processes
- Proactive monitoring

## Roadmap

- Read Google SRE book
- Learn the tools used in SRE; automation tools, monitoring tools, etc. 
- Build a foundation in SysAdmin
- Practice and practice

## Mindset

- failure is the nature of the system: identify the potential failures and solving them ahead of time
- automate everything
- monitoring and logging are just key to the SRE role:
  - monitoring is going to give the ability to anticipate the failure and proactively solve them.
  - logging is when you get an unanticipated failure, it allow you to go back to see what happened. then do a RCA. have to solve it in future by automation. 
- fee

## Observability

Observability is a process that prepare the software team for uncertainties when the software goes live for end users.  Detect abnormal behaviors, collect information that helps developers understand what causes the problem. 

### Metrics

Metrics are quantifiable values that reflect an application's performance or system health. SRE teams use metrics to determine if the software consumes excessive resources or behaves abnormally.

### Logs

SRE software generates detailed, timestamped information called logs in response to specific events. Software engineers use logs to understand the chain of events that lead to a particular problem. 

### Traces

Traces are observations of the code path of a specific function in a distributed system. help software developers detect latency issues and improve software performance.

## Monitoring

Monitoring is a process of observing predefined metrics in an application. Developers decide which parameters are critical in determining the application's health and set them in monitoring tools. Site reliability engineering (SRE) teams collect critical information that reflects the system performance and visualize it in charts.

In SRE, software teams monitor these metrics to gain insight into system reliability.

Latency 

Latency describes the delay when the application responds to a request. 

Traffic

Traffic measures the number of users concurrently accessing your service. It helps software teams accordingly budget computing resources to maintain a satisfactory service level for all users.

Errors

An error is a condition where the application fails to perform or deliver according to expectations. SRE teams use software tools to automatically track and respond to errors in the application.

Saturation

Saturation indicates the real-time capacity of the application. A high level of saturation usually results in degrading performance. Site reliability engineers monitor the saturation level and ensure it is below a particular threshold. 

## Key Metrics

Site reliability engineering (SRE) teams measure the quality of service delivery and reliability using the following metrics. 

### Service-Level Agreements (SLAs)

Service-level objectives (SLOs) are specific and quantifiable goals that you are confident the software can achieve at a reasonable cost to other metrics, such as the following: 

- Uptime, or the time a system is in operation
- System throughput
- System output
- Download rate, or the speed at which the application loads

An SLO promises delivery through the software to the customer. For example, you set a 99.95% uptime SLO for your company's food delivery app.

### Service-Level Indicators (SLIs)

Service-level indicators (SLIs) are the actual measurements of the metric an SLO defines. In real-life situations, you might get values that match or differ from the SLO. For example, your application is up and running 99.92% of the time, which is lower than the promised SLO. 

### Service-Level Objectives (SLOs)

Service-level agreements

The service-level agreements (SLAs) are legal documents that state what would happen when one or more SLOs are not met. For example, the SLA states that the technical team will resolve your customer's issue within 24 hours after a report is received. If your team could not resolve the problem within the specified duration, you might be obligated to refund the customer.

### Error Budgets

Error budgets are the noncompliance tolerance for the SLO. For example, an uptime of 99.95% in the SLO means that the allowed downtime is 0.05%. If the software downtime exceeds the error budget, the software team devotes all resources and attention to stabilize the application.

## How does SRE work

The SRE team sets the key metrics for SRE and creates an error budget determined by the system's level of risk tolerance.

A site reliability engineer uses a service to monitor performance metrics and detect anomalous application behavior. If there are issues with the application, the SRE team submits a report to the software engineering team. The developers fix the reported cases and publish the updated application.

### DevOps

**DevOps is a software culture** that breaks down the traditional boundary of development and operation teams. With DevOps, developers and operation engineers no longer work in silos. Instead, they use software tools to improve collaboration and keep up with the rapid pace of software update releases.

**SRE is the practical implementation of DevOps**. **DevOps provides the philosophical foundation** of what must be done to maintain software quality amidst the increasingly shortened development timeline. Site reliability engineering offers the answers to how to achieve DevOps success. SRE ensures that the DevOps team strikes the right balance between speed and stability.

## SRE Responsibilities

A site reliability engineer is an IT expert who uses automation tools to monitor and observe software reliability in the production environment. They are also experienced in finding problems in software and writing codes to fix them. They are typically former system administrators or operation engineers with good coding skills.

### Operations

**Site reliability engineers spend up to half of their time in operations work**. This includes several tasks, such as the following: 

- Emergency incident response
- Change management
- IT infrastructure management

The engineers use SRE tools to automate several operations tasks and increase team efficiency.

### System support

Site reliability engineers work closely with the development team to create new features and stabilize production systems. They **create an SRE process** for the entire software team and are on hand to support escalation issues. More importantly, site reliability teams provide documented procedures to customer support to help them effectively deal with complaints. 

### Process improvement

Site reliability engineers **improve the software development lifecycle by holding post-incident reviews**. The SRE team documents all software problems and respective solutions in a shared knowledge base. This helps the software team efficiently respond to similar issues in the future. 

## Common Tools

SRE use different types of tools to facilitate monitoring, observation, and incident response. 

### Container orchestrator

Software developers use a container orchestrator to run containerized applications on various platforms. Containerized applications store their code files and related resources within a single package called a container.

### On-call management tools

On-call management tools are software that allow SRE teams to plan, arrange, and manage support personnel who deal with reported software problems. SRE teams use the software to ensure there is always a support team on standby to receive timely alerts on software issues. 

### Incident response tools

Incident response tools ensure a clear escalation pathway for detected software issues. SRE teams use incident response tools to categorize the severity of reported cases and deal with them promptly. The tools can also provide post-incident analysis reports to prevent similar problems from happening again. 

### Configuration management tools

Configuration management tools are software that automate software workflow. SRE teams use these tools to remove repetitive tasks and become more productive. For example, site reliability engineers use AWS OpsWorks to automatically set up and manage servers on AWS environments. 

## AWS

**AWS Management and Governance** services provide the necessary tools for software teams to build, scale, and deploy distributed applications without compromising system reliability. Site reliability engineering (SRE) teams use various AWS Management and Governance services to monitor and govern AWS and on-premises computing resources:

- **AWS Service Catalog** allows SRE teams to catalog, manage, and quickly deploy IT services
- **AWS Systems Manager** provides a centralized management hub for site reliability engineers to gain operational insights into software computing resources
- **AWS Proton** is an automated management tool for deploying containerized and serverless applications