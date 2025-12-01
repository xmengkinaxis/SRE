# SRE Basic Terms

- [SRE Basic Terms](#sre-basic-terms)
  - [REFERENCE](#reference)
  - [NOTE](#note)
  - [Distributed System](#distributed-system)
  - [Containerization](#containerization)
  - [Containers](#containers)
  - [Docker](#docker)
  - [Cloud Native Apps](#cloud-native-apps)
  - [Cluster](#cluster)
  - [Infrastructure as Code (IaC)](#infrastructure-as-code-iac)
  - [Infrastructure as a Service (IaaS)](#infrastructure-as-a-service-iaas)
  - [Kubernetes](#kubernetes)
  - [Pod](#pod)
  - [Nodes](#nodes)
  - [Helm](#helm)
  - [Terraform](#terraform)
  - [Terragrunt](#terragrunt)
  - [Multitenancy](#multitenancy)

## REFERENCE

[Cloud Native Glossary](https://glossary.cncf.io/)
[What is SRE?](https://www.redhat.com/en/topics/devops/what-is-sre)

## NOTE

- Turn to Helm for packaging applications, Terraform for infrastructure provisioning, and Terragrunt for orchestrating Terraform configurations.
- The combination of Docker, Helm, Terraform, and Terragrunt empowers teams to deploy complex applications to Kubernetes in a streamlined, declarative, and consistent manner.
  - Docker images encapsulate the application code and its dependencies, making deployments portable and reliable. 
  - Helm charts simplify Kubernetes deployments by providing reusable and versioned templates. 
  - Terraform offers a declarative approach to provisioning Kubernetes infrastructure. 
  - Finally, Terragrunt orchestrates the entire process, ensuring consistency and DRY configurations across environments.
- Ideas???
  - Be lazy; automatic everything to avoid toils and to be consistent
  - introduce another layer of abstraction; use these declarative languages; not worry about how these actually do
  - having a single source of truth helps visibility, maintainability and increases durability and/or stability
  - having control over what is going to be deployed is a must-have
- Minikube
  - [Minikub](https://kubernetes.io/docs/tasks/tools/), which offers an excellent way to work with a single-node Kubernetes cluster locally.
- Helm
  - [Helm installation](https://helm.sh/docs/v2/using_helm/#installing-helm)
- Terraform vs Kubernetes
  - Terraform is a tool for provisioning and managing infrastructure as code, such as servers, databases, and networking across multiple cloud providers.
  - Kubernetes is a container orchestration platform that manages the deployment, scaling, and operation of containerized applications.
  - Terraform builds the infrastructure where Kubernetes might run. Kubernetes then manages application workloads on that infrastructure. They often work together but solve different layers of the stack, with Terraform setting up infrastructure and Kubernetes managing application-level operations.
  - Terraform focuses on provisioning infrastructure components and targets the Infrastructure as Code space.
  - Kubernetes aims to enable us to run container workloads and targets the container orchestration space.
  - Kubernetes and Terraform complement each other since they operate at two different levels and can be utilized in parallel.
  - A typical model that cloud practitioners adopt is to use Terraform to provision infrastructure resources (e.g. Kubernetes clusters) and use Kubernetes to manage the containerized apps that run on top of the clusters.
  - Another approach is to use Terraform to manage Kubernetes-specific application components as well. This model has the advantage of adding the Terraform workflow to Kubernetes components. This way, IT operators can detect configuration drift on Kubernetes and manage infrastructure and application resources with the same workflow and configuration language. This approach has a significant disadvantage since Terraform requires a well-defined schema for each managed resource. Thus each Kubernetes resource needs to be translated into a Terraform schema to be available. This dependency makes maintaining Kubernetes resources through Terraform cumbersome at times.
- Terraform vs Helm
  - Infrastructure Provisioning vs. Application Deployment;
    - Terraform excels in provisioning and managing infrastructure resources across various cloud providers. It is suitable for defining and managing virtual machines, Kubernetes clusters, storage, and networking components.
    - Helm, however, focuses on packaging and deploying applications on Kubernetes. It streamlines the installation, upgrading, and rollback of containerized applications.
  - Infrastructure as Code vs. Application Packaging
    - Terraform's strength lies in its ability to define infrastructure resources as code. This approach ensures that infrastructure changes can be version-controlled, reviewed, and shared among teams.
    - Helm, being a package manager, specializes in bundling applications and their configurations into portable packages. This allows for consistent deployment across different environments.
- jife

## Distributed System

A distributed system is a collection of autonomous computing elements connected over a network that appears to users as a single coherent system. Generally referred to as nodes, these components can be hardware devices (e.g. computers, mobile phones) or software processes. Nodes are programmed to achieve a common goal and, to collaborate, they exchange messages over the network.

Distributed systems allow for horizontal scaling (e.g. adding more nodes to the system whenever needed). This can be automated allowing a system to handle a sudden increase in workload or resource consumption.

## Containerization

Containerization is the process of packaging of application code including libraries and dependencies required to run the code into a single lightweight executable—called container image.

Container images are lightweight (unlike traditional VMs) and the containerization process requires a file with a list of dependencies. A container image is stored by a unique identifier that is tied to its exact content and configuration. As containers are scheduled and rescheduled, they are always reset to their initial state which eliminates configuration drift.

a next-generation virtualization and automation solution after Hypervisor Virtualization. It widely applied today because of the breakthrough effect with outstanding advantages in creating and deploying applications faster, more scalable and more securely than traditional methods.

## Containers

A container is a running process with resource and capability constraints managed by a computer’s operating system. The files available to the container process are packaged as a container image. Containers run adjacent to each other on the same machine, but typically the operating system prevents the separate container processes from interacting with each other.

## Docker

a number one software to create, manage and run containers

Encapsulating Application Code for Portability. Docker has become the de facto standard for containerization.

Docker containers have revolutionized software development by encapsulating applications, libraries, and dependencies in a consistent and portable environment. With Docker, you can package your project's application code and all its dependencies into a single, lightweight image. This image can be easily shared, version-controlled, and deployed across different environments without worrying about variations in the underlying infrastructure.

By leveraging Docker images, we can reduce the infamous "it works on my machine" problem. This consistency is especially valuable when deploying applications to Kubernetes clusters, as it eliminates the need to deal with subtle environment differences that could lead to production issues.

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

Kubernetes (K8s) is an open-source system for container orchestration, automating deployments, and managing containerized apps. Its powerful orchestration system enables applications to scale seamlessly and achieve high availability.

Kubernetes strives to be cloud agnostic at its core, providing great flexibility in running workloads across cloud and on-premises environments.

One of its main benefits is the self-healing capabilities it provides. Containers that fail are automatically restarted and rescheduled, nodes can be configured to be automatically replaced, and traffic is served only by healthy components based on health checks.  

Rollouts are handled progressively, and Kubernetes provides smart mechanisms to monitor application health during deployments. Rolling back problematic changes happens automatically if the application health doesn’t report a healthy status after a new deployment.

Kubernetes handles service discovery and load-balances traffic between similar pods natively without the need for complex external solutions.

Kubernetes provides a cluster of nodes, a group of worker machines that run containerized applications. Each node hosts pods that hold application workload containers. The brain of the whole system is the control plane. Each cluster consists of several components that manage the worker nodes and pods and guarantee operational continuity.

[Cluster Architecture](https://kubernetes.io/docs/concepts/architecture/) and [Core Components](https://kubernetes.io/docs/concepts/overview/components/): 

- Control Plane
  - The **API server** is the component exposing the Kubernetes API and operates as the front-end of the control plane by handling all the communication between other parts.
  - The **etcd** (a distributed /etc) component is used to store all cluster data and state.
  - The **scheduler** manages how pods are assigned to nodes and takes all the workload scheduling decisions.
  - The **controller manager** components run different controller processes to ensure that the cluster’s desired state matches its current state.
  - The **cloud controller** manager integrates Kubernetes clusters with external cloud providers, embeds their logic, and links the Kubernetes API with the Cloud Provider’s API.
- On each worker node
  - the **kubelet** (the primary "node agent") is the agent responsible for running containers in pods, 
  - **kube-proxy** is the component that adds the necessary networking capabilities for communication between pods and nodes. 

## Pod

Within a Kubernetes environment, a pod acts as the most basic deployable unit. It represents an essential building block for deploying and managing containerized applications. Each pod contains a single application instance and can hold one or more containers. Kubernetes manages pods as part of a larger deployment and can scale pods vertically or horizontally as needed.

While containers generally act as independent units that run and control a particular workload, there are cases when containers need to interact and be controlled in a tightly coupled manner.

Pods bundle closely tied containers into a single unit, significantly simplifying container operations. 

Memory and CPU allocation can be defined either on a pod level, allowing the containers inside to share resources in a flexible way, or per container.

## Nodes

A node is a computer that works in concert with other computers, or nodes, to accomplish a common task. Take your laptop, modem, and printer, for example. They are all connected over your wifi network communicating and collaborating, each representing one node. In cloud computing, a node can be a physical computer, a virtual computer, referred to as a VM, or even a container

## Helm

Helm is a package manager for Kubernetes that simplifies the deployment and management of applications on Kubernetes clusters. Helm uses a packaging format called charts. A **Helm chart** is a collection of files that describe a related set of Kubernetes resources. A single chart might be used to deploy something simple, like a memcached pod, or something complex, like a full web app stack with HTTP servers, databases, caches, and so on.

Helm, essentially a package manager for Kubernetes, simplifies the deployment process by providing a templating engine and a collection of pre-configured packages called "charts." These charts define the resources needed to run an application in Kubernetes, including deployments, services, and configuration files.

With Helm charts, developers can easily define, version, and manage complex Kubernetes deployments as code.The templating engine allows for parameterization, enabling the reuse of chart configurations with different values for each environment (e.g., development, staging, production). This abstraction helps standardize the deployment process and reduces the chances of human errors when deploying complex applications.

Key Features of Helm:

- Templates: Helm charts are templates for Kubernetes YAML files, which can be customized with variables and flow control statements.
- Package Management: Helm manages Kubernetes applications through Helm charts which support versioning, which makes it easy to roll back to an earlier version if something goes wrong.
- Dependencies: Helm charts can define dependencies on other charts, allowing complex applications to be composed from individual components.

Helm has 4 basic concepts:

- Chart: a collection of YAML files; bundle of the Kubernetes resources needed to build a Kubernetes application. For ease of visualization, Helm Chart can be compared like a Docker Image.
- Config: a configuration in the values.yaml file, which contains configuration explicit to a release of Kubernetes application.
- Release: a chart instance is loaded into Kubernetes. It can be viewed as a version of the Kubernetes application running based on Chart and associated with a specific Config.
- Repositories: a repository of published Charts. These can be private repositories that are only used within the company or public through the Helm Hub. 

Helm has a fairly simple client-server architecture, including a CLI client and an in-cluster server running in the Kubernetes cluster

- **Helm Client**: Provides the developer to use it a command-line interface (CLI) to work with Charts, Config, Release, Repositories. Helm Client will interact with Tiller Server, to perform various actions such as install, upgrade and rollback with Charts, Release.
- **Tiller** Server: an in-cluster server in the Kubernetes cluster, interacting with the Helm Client and communicating with the Kubernetes API server. Thus, Helm can easily manage Kubernetes with tasks such as install, upgrade, query and remove for Kubernetes resources.

Helm focuses on application packaging and deployment. Helm is a Kubernetes package manager that streamlines the installation and management of containerized applications. It uses "charts" as packaged applications, containing all the necessary Kubernetes resources, configuration files, and dependencies. This allows for simplified application deployment, version management, and rollbacks.

A Helm Chart is **a packaging format** used to define, install, upgrade, deploy, share, and manage Kubernetes applications. It lets you group multiple Kubernetes resources—like Deployments, Services, and Persistent Volumes—into one reusable unit. Helm Charts automate complex Kubernetes deployments by templating configurations and managing lifecycle upgrades. Charts describe even the most complex apps, provide repeatable application installation, and serve as a single point of authority.

Deploying real-world applications in Kubernetes usually involves several moving parts: app containers, config maps, secrets, service accounts, and storage. Managing all of this manually becomes inefficient fast. Helm solves this by turning infrastructure into modular, repeatable packages. It reduces human error, accelerates CI/CD pipelines, and makes rollbacks as simple as a single command.

How a Helm Chart Is Organized

- Each Helm Chart is a folder that follows a clear structure, making it easier to manage, update, and reuse across environments.
- **Chart.yaml** – It contains metadata like the chart name, version, and a brief description.
- **values.yaml** – Defines default configuration values that can be overridden at deployment.
- **templates/** – Holds the actual Kubernetes manifest templates using Go templating.
- **charts/** – (Optional) Includes subcharts or external dependencies that the main chart relies on.

Helm is built for scaling, upgrading, and maintaining production environments.

good habits:

- Keep values.yaml files environment-specific (dev, staging, prod)
- Store your charts in version control alongside app code
- Don’t hardcode secrets—use tools like Sealed Secrets or a vault
- Lint charts before deploying with **helm lint**
- Use subcharts for reusable services across apps

commands:

- helm lint: correct any syntax error
- helm template:  replace the placeholder object with original values and show the complete file in console.
- helm install --dry-run: pretend to install the manifests file and try to display the manifests files.
- helm install prod: // kubectl create namespace prod (dev) in advance
- kubectl get all -n prod: confirm the deployment is successful
- helm list: check the number of releases in the host.
- helm upgrade (prod)：if any environment needs to update with image details, versions, replica count, storage memory etc…, we can do that with upgrade by without bringing down the original state
- helm rollback (prod): rollback to previous state
- helm package: package the chart and deploy it to Github, S3, or any chart repository
- helm uninstall (dev): uninstall the helm release; it will remove all of the resources associated with the last release of the chart.

## Terraform

Terraform: Declarative Kubernetes Configurations

While Docker and Helm handle application packaging and Kubernetes deployments, managing the underlying infrastructure can be challenging. Terraform, an Infrastructure as Code (IaC) tool, bridges this gap by providing a declarative way to define, provision, and manage infrastructure resources.

With Terraform's Kubernetes provider, developers can create Kubernetes resources like namespaces, services, and secrets as code. This approach ensures that the infrastructure setup is repeatable, version-controlled, and easily shareable across teams. Additionally, by maintaining the state of the infrastructure, Terraform can automatically manage updates and ensure that the desired state matches the actual state.

Bonus - using the Helm Terraform provider, we can explicitly wire up dependencies between terraform resources, so that the output of a Terraform module can be used as an input to a Helm chart.

Terraform is a tool that allows us to safely and predictably manage infrastructure at scale using cloud-agnostic and infrastructure as code principles. It is a powerful tool developed by Hashicorp that enables infrastructure provisioning both on the cloud and on-premises. 

Terraform is written in a declarative configuration language, Hashicorp Configuration Language (HCL), and facilitates the automation of infrastructure management in any environment.

Modules provide excellent reusability and code-sharing opportunities to boost the collaboration and productivity of teams operating on the cloud. Providers are plugins that offer integration and interaction with different APIs and are one of the main ways to extend Terraform’s functionality. 

Terraform keeps an internal state of the managed infrastructure, which represents resources, configuration, metadata, and their relationships. The state is actively maintained by Terraform and utilized to create plans, track changes, and enable modifications of infrastructure environments. The state should be stored remotely to allow teamwork and collaboration as a best practice.

The core Terraform workflow consists of three concrete stages. First, we generate the infrastructure as code configuration files representing our environment’s desired state. Next, we check the output of the generated plan based on our manifests. After carefully reviewing the changes, we apply the plan to provision infrastructure resources.

Terraform is an infrastructure provisioning tool that enables users to define and manage their infrastructure as code. It provides a declarative language to describe the desired state of infrastructure resources, such as virtual machines, Kubernetes nodes, storage, and networking components.

Terraform then automates the provisioning and management of these resources across multiple cloud platforms, making it highly versatile. By executing Terraform, the desired infrastructure is automatically provisioned, ensuring consistency and reproducibility.

## Terragrunt

Terragrunt: Orchestrating Terraform Configurations
As infrastructure grows in complexity, managing multiple Terraform configurations across different environments becomes challenging. Terragrunt, an open-source tool, acts as a thin wrapper around Terraform, enabling configuration reuse and better orchestration.

Terragrunt allows developers to follow the Don't Repeat Yourself (DRY) principle by sharing common Terraform configurations across different environments. With Terragrunt's ability to manage dependencies and inheritance, teams can maintain a clear and organized codebase while ensuring consistency and reducing errors.

## Multitenancy

Multitenancy (or multi-tenancy) refers to a single software installation that serves multiple tenants. A **tenant** is a user, application, or a group of users/applications that utilize the software to operate on their own data set. These tenants don’t share data (unless explicitly instructed by the owner) and may not even be aware of one another.

A tenant can be as small as one independent user with a single login ID — think personal productivity software — or as large as an entire corporation with thousands of login IDs, each with its own privileges yet interrelated in multiple ways.

Without multitenancy, each tenant would need a dedicated software installation. This increases resource utilization and maintenance efforts, ultimately software costs.

Multitenant software provides each tenant a segregated environment (work data, settings, list of credentials, etc.), simultaneously serving multiple tenants. From a tenant’s perspective, each has its dedicated software installation, although, in reality, they are all sharing one.

With multitenant software, tenants share the resources of one installation without affecting each other or only in predefined and controlled ways.