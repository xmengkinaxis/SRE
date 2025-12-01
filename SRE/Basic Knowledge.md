## REFERENCE
[Cloud Native Glossary](https://glossary.cncf.io/)

## Distributed System
A distributed system is a collection of autonomous computing elements connected over a network that appears to users as a single coherent system. Generally referred to as nodes, these components can be hardware devices (e.g. computers, mobile phones) or software processes. Nodes are programmed to achieve a common goal and, to collaborate, they exchange messages over the network.

Distributed systems allow for horizontal scaling (e.g. adding more nodes to the system whenever needed). This can be automated allowing a system to handle a sudden increase in workload or resource consumption.

## Containers
A container is a running process with resource and capability constraints managed by a computer’s operating system. The files available to the container process are packaged as a container image. Containers run adjacent to each other on the same machine, but typically the operating system prevents the separate container processes from interacting with each other.

## Cloud Native Apps
Cloud native applications are specifically designed to take advantage of innovations in cloud computing. These applications integrate easily with their respective cloud architectures, taking advantage of the cloud’s resources and scaling capabilities. It also refers to applications that take advantage of innovations in infrastructure driven by cloud computing. Cloud native applications today include apps that run in a cloud provider’s datacenter and on cloud native platforms on-premise.

## Cluster
A cluster is a group of computers or applications called nodes that work together towards a common goal. In cloud native computing, the term is often applied when talking about a Kubernetes cluster. It can be seen as a specific kind of distributed system where the nodes are a bit more tightly coupled.

## Infrastructure as Code (IaC)
Infrastructure as code is the practice of storing the definition of infrastructure as one or more files. This replaces the traditional model where infrastructure as a service is provisioned manually, usually through shell scripts or other configuration tools

Building applications in a cloud native way requires infrastructure to be disposable and reproducible.

By representing the data center resources such as servers, load balancers, and subnets as code, it allows infrastructure teams to have a single source of truth for all configurations and also allows them to manage their data center in a CI/CD pipeline, implementing version control and deployment strategies.

## Infrastructure as a Service (IaaS)
Infrastructure
Infrastructure as a service, or IaaS, is a cloud computing service model that offers physical or virtualized compute, storage, and network resources on-demand on a pay-as-you-go model. Cloud providers own and operate the hardware and software, available to consumers in public, private, or hybrid cloud deployments.

An on-demand infrastructure allows them to rent compute resources as needed and defer large capital expenditures, or CAPEX, while giving them the flexibility to scale up or down.

IaaS reduces the upfront costs of experimenting or trying a new application and provides facilities to rapidly deploy infrastructure. A cloud provider is an excellent option for development or test environments, which helps developers experiment and innovate.

## Kubernetes
Kubernetes, often abbreviated as K8s, is an open source container orchestrator. It automates the lifecycle of containerized applications on modern infrastructures, functioning as a “datacenter operating system” that manages applications across a distributed system.

Kubernetes schedules containers across nodes in a cluster, bundling several infrastructure resources such as load balancer, persistent storage, etc. to run containerized applications.

Kubernetes enables automation and extensibility, allowing users to deploy applications declaratively (see below) in a reproducible way. 

Similar to traditional infrastructure as code tools, Kubernetes helps with automation but has the advantage of working with containers. Containers are more resistant to configuration drift than virtual or physical machines.

Additionally, Kubernetes works declaratively, which means that instead of operators instructing the machine how to do something, they describe — usually as manifest files (e.g., YAML) — what the infrastructure should look like. Kubernetes then takes care of the “how”. This results in Kubernetes being extremely compatible with infrastructure as code.

## Pod
Within a Kubernetes environment, a pod acts as the most basic deployable unit. It represents an essential building block for deploying and managing containerized applications. Each pod contains a single application instance and can hold one or more containers. Kubernetes manages pods as part of a larger deployment and can scale pods vertically or horizontally as needed.

While containers generally act as independent units that run and control a particular workload, there are cases when containers need to interact and be controlled in a tightly coupled manner.

Pods bundle closely tied containers into a single unit, significantly simplifying container operations. 

Memory and CPU allocation can be defined either on a pod level, allowing the containers inside to share resources in a flexible way, or per container.

## Nodes
A node is a computer that works in concert with other computers, or nodes, to accomplish a common task. Take your laptop, modem, and printer, for example. They are all connected over your wifi network communicating and collaborating, each representing one node. In cloud computing, a node can be a physical computer, a virtual computer, referred to as a VM, or even a container