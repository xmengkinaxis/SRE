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