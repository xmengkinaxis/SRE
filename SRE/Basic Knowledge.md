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
    - [Kubnernetes API](#kubnernetes-api)
  - [Pod](#pod)
  - [Nodes](#nodes)
  - [Helm](#helm)
  - [Terraform](#terraform)
  - [Terragrunt](#terragrunt)
  - [Multitenancy](#multitenancy)
  - [YAML](#yaml)
  - [💡 K8s Service 的真实含义和作用](#-k8s-service-的真实含义和作用)
    - [核心痛点与 Service 的解决方案](#核心痛点与-service-的解决方案)
  - [🧐 为什么叫它 Service（服务）？](#-为什么叫它-service服务)
  - [🌐 K8s Service 的类型](#-k8s-service-的类型)
  - [🏷️ 1. Label（标签）是什么？](#️-1-label标签是什么)
    - [作用：组织和识别](#作用组织和识别)
  - [🔎 2. Selector（选择器）是什么？](#-2-selector选择器是什么)
    - [作用：定位和管理](#作用定位和管理)
    - [常见的 Selector 使用场景：](#常见的-selector-使用场景)
  - [🔗 3. Label 和 Selector 的关系（核心）](#-3-label-和-selector-的关系核心)
    - [关系图示](#关系图示)

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

Docker is the platform for creating, deploying, and running applications in containers. It provides a consistent environment for applications using containers. It can be used as the container runtime for Kubernetes. 

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

A **pod** is the smallest deployable unit in Kubernetes, encapsulating one or more containers that share storage and network resources. This flexibility is essential for implementing complex applications effectively within a Kubernetes cluster.

Scaling an application in Kubernetes typically involves increasing the number of Pods that run the application, ensuring better resource utilization and improved performance.

[Cluster Architecture](https://kubernetes.io/docs/concepts/architecture/) and [Core Components](https://kubernetes.io/docs/concepts/overview/components/): 

- Control Plane
  - The **API server** is the component exposing the Kubernetes API and operates as the front-end of the control plane by handling all the communication between other parts.
  - The **etcd** (a distributed /etc) component is used to store all cluster data and state. It is a distributed reliable key-value store used by kubernetes to store all configuration and metadata used to manage the cluster.
  - The **scheduler** manages how pods are assigned to nodes and takes all the workload scheduling decisions. It is responsible for distributing work among multiple nodes by deciding which nodes will run specific pods. This function is crucial for optimizing resource utilization and ensuring efficient operation within a Kubernetes cluster. 
  - The **controller manager** components run different controller processes to ensure that the cluster’s desired state matches its current state.
  - The **cloud controller** manager integrates Kubernetes clusters with external cloud providers, embeds their logic, and links the Kubernetes API with the Cloud Provider’s API.
- On each worker node
  - the **kubelet** (the primary "node agent") is the agent responsible for running containers in pods,
  - **kube-proxy** is the component that adds the necessary networking capabilities for communication between pods and nodes.

- kubectl
  - kubectl run; start a pod; deploy an application
  - kubectl cluster-info
  - kubectl get nodes; list all nodes of a cluster; find out how many nodes in this cluster
    - kubectl get nodes - o wide; // get os-image and kernel-version
  - kubectl config view; // show the current Config
  - kubectl get pods --namespace kube-system; // see Helm's Tiller running
  - kubectl describe pod (nginx); // See a pod detail
  - kubectl describe deploy tiller-deploy --namespace=kube-system
  - kubectl apply -f pod.yaml // create(apply) the pod
  - kubectl version // the version of Kubernetes

 **container runtime** is the underlying framework responsible for running applications within containers, such as those created with Docker.
 **kubectl** is the command-line tool specifically designed for managing Kubernetes clusters, allowing you to interact with cluster resources and deploy applications effectively.

### Kubnernetes API

API Server:

- The central component that exposes the Kubernetes API.
- All communication with the cluster, whether from kubectl, other control plane components, or external tools, goes through the API server.

API Objects:

- Everything in Kubernetes is represented as an API object (e.g., Pods, Deployments, Services, ConfigMaps, Secrets, Nodes, Namespaces).
- These objects have a defined schema and state, which is stored in etcd.

API Verbs:

- Standard operations that can be performed on API objects:
- get: Retrieve a specific object.
- list: Retrieve a collection of objects (e.g., all Pods in a Namespace).
- create: Create a new object.
- update: Replace an existing object with a new definition.
- patch: Apply partial updates to an existing object.
- delete: Delete an object.
- watch: Monitor changes to objects in real-time.

API Groups and Versions:

- Kubernetes API objects are organized into API Groups (e.g., apps, batch, networking.k8s.io).
- Each API Group can have multiple versions (e.g., v1, v1beta1). This allows for API evolution and backward compatibility.

Common Interactions:

- Inspecting Resources: kubectl get <resource>, kubectl describe <resource> <name>
- Creating/Updating Resources: kubectl apply -f <manifest.yaml>
- Deleting Resources: kubectl delete <resource> <name>
- Managing Deployments: kubectl rollout status deployment/<name>, kubectl scale deployment/<name> --replicas=<count>
- Accessing Logs: kubectl logs <pod_name>
- Debugging Pods: kubectl exec -it <pod_name> -- <command>, kubectl port-forward pod/<pod_name> <local_port>:<remote_port>

Note: While kubectl provides a convenient command-line interface to interact with the Kubernetes API, direct API interaction can be performed using client libraries in various programming languages (Go, Python, Java, etc.) or by making direct HTTP requests.

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

A Helm chart describes how to manage a specific application on Kubernetes. It consists of metadata that describes the application, plus the infrastructure needed to operate it in terms of the standard Kubernetes primitives. Each chart references one or more container images that contain the application code to be run.

Despite the fact we can run application containers using the Kubernetes command line (kubectl), the easiest way to run workloads in Kubernetes is using the ready-made Helm charts.

How a Helm Chart Is Organized

- Each Helm Chart is a folder that follows a clear structure, making it easier to manage, update, and reuse across environments.
- **Chart.yaml** – It contains metadata info like the chart name, version, and a brief description.
- **values.yaml** – Defines default configuration values that can be overridden at deployment. the template files collect deployment information from this file. It can customize the helm chart.
- **templates/** – Holds the actual Kubernetes manifest templates using Go templating. stores the actual yaml files. It holds all the configurations for the application. It also includes a tests directory. It use [Golang](https://www.geeksforgeeks.org/go-language/go/) templating format to assemble the configurations from values.yaml or command line and convert the complete configuration into a Kubernetes manifest.
- **charts/** – (Optional) Includes subcharts or external dependencies that the main chart relies on.

Helm terminologies and core components

- Chart: It is a package of containing pre-configured kubernetes resources.
- Release: It is an instance of running charts in a kubernetes resource.
- Repository: It is a collection of charts that can be shared and stored.
- Values: It is useful for configuration settings that can help in customizing chart deployments.
- Helm Chart: It is a helm package manager that contains a collection of kubernetes resource definitions.

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
- helm list: check the number of releases in the host; list all Helm releases.
- helm upgrade (prod)：if any environment needs to update with image details, versions, replica count, storage memory etc…, we can do that with upgrade by without bringing down the original state; update a Helm release.
- helm rollback (prod): rollback to previous state
- helm package: package the chart and deploy it to Github, S3, or any chart repository
- helm uninstall (dev): uninstall the helm release; it will remove all of the resources associated with the last release of the chart.
- helm create (mychart): create a chart
- helm version: show both the client and server version
- helm init; // install on MacOs: brew install kubernetes-helm
- helm repo list
- helm repo search (mariadb)
- helm install stable/mariadb
- helm status // ???
- helm delete --deleted (--all)/ ???

For Kubernetes, it is equivalent to yum(Red Hat), apt(Debian、Ubuntu), or homebrew(macOS, Linux).

A *release* represent an instance of a chart running in a Kubernetes cluster. Each release has its own unique name. 

[In Helm 3, Tiller will be removed](https://helm.sh/blog/helm-3-preview-pt2/), because the tiller inside a K8s cluster has too much poewr such as CREATE/UPDATE/DELETE and it causes some security issues. So, the Helm 3 client library will communicate directly with the Kubernetes API server not via Tiller.

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

## YAML

Compared with XML and JSON, YAML is much simpler in presenting the same data.

Must have a space after colon ":" in Key-Value Pair. Sibling should have the same dents, but how many spaces do not matter.  

YAML in Kubernetes:

- always contains four keys and they are the root/top properties.
  - apiVersion: v1 of Kubernetes objects, like Pod
  - kind: type of object to create; e.g. Pod, Server, Deployment
  - metadata: data about the object; e.g. name, labels (dict); after labeling, it is easy to group these pods
  - spec: specification on the additional information for the object; depend on the object; a list of containers
- fe

can use some extension or plugin to hight the syntax error or validate the content 

---

您提了一个非常好的观点！确实，**"Service"** 这个词在 IT 领域太过通用（例如，Web Service, Windows Service, 后端服务等），很容易让人对 Kubernetes 中的 `Service` 产生困惑。

在 Kubernetes (K8s) 中，`Service` 的真实含义和作用，与我们日常说的“服务”有所不同。

---

## 💡 K8s Service 的真实含义和作用

Kubernetes 中的 **Service** 是一种 **抽象层**，它解决的核心问题是 **Pod 的不稳定性和发现性**。

简单来说，K8s Service 有两个主要职责：

1.  **负载均衡器 (Load Balancer):** 将客户端的请求分散到多个后端的 Pod 上。
2.  **稳定的网络端点 (Stable Network Endpoint):** 为一组动态变化的 Pod 提供一个固定的 IP 地址和 DNS 名称。

### 核心痛点与 Service 的解决方案

| 痛点 | K8s Service 如何解决 |
| :--- | :--- |
| **Pod 是临时的** | Pod 随时可能因为扩容、升级、重启、故障等原因被销毁并重建，其 IP 地址会改变。 |
| **Service 提供了稳定的 IP 和 DNS 名称**。前端应用或客户端不需要知道后端 Pod 的具体 IP。 |
| **Pod 发现困难** | 客户端需要知道哪些 Pod 正在运行，并且能够将请求发送到健康的 Pod 上。 |
| **Service 充当“代理”**。它使用 **Selector (标签选择器)** 自动跟踪和监控一组 Pod，并将请求路由到这些 Pod。 |
| **负载均衡** | 客户端需要将流量均匀地分散到所有健康的后端 Pod 上。 |
| **Service 内置负载均衡机制**（通常是 Round-Robin 或 Least Connections），确保流量均匀分配。 |



---

## 🧐 为什么叫它 Service（服务）？

虽然名字很通用，但 Kubernetes 沿用这个名称是因为它确实将一组 Pod 暴露为一个可用的“服务”：

* **对内：** 它使集群内的其他 Pod 可以通过一个固定的内部 DNS 名称访问后端应用（例如，直接访问 `my-database-service`）。
* **对外：** 它定义了应用如何从集群外部（Internet）被访问。

所以，与其说它是一个服务，不如说它是一个 **“服务抽象/发现层”** 或 **“网络代理”**。

---

## 🌐 K8s Service 的类型

Kubernetes Service 有几种不同的类型，决定了它如何将应用暴露给网络：

| Service 类型 | 作用 | 暴露范围 |
| :--- | :--- | :--- |
| **ClusterIP (默认)** | 为 Service 提供一个集群内部的 IP 地址，**只能**在集群内部访问。 | 仅限集群内部 |
| **NodePort** | 在集群的每个节点 (Node) 上打开一个静态端口，外部流量可以通过 `<NodeIP>:<NodePort>` 访问。 | 暴露给外部 |
| **LoadBalancer** | 仅在云环境中可用。它会自动在云平台 (如 AWS, GCP, Azure) 上配置一个外部的云负载均衡器，并将流量导入集群。 | 暴露给外部 (推荐) |
| **ExternalName** | 将 Service 映射到一个外部的 DNS 名称，而不是一个集群内部 IP。 | 外部 DNS |

总而言之，您对 `Service` 名字的困惑是合理的，但请记住它在 K8s 中的特定含义：**一个为一组后端 Pod 提供稳定网络访问和负载均衡的抽象层。**

这是一个理解 Kubernetes 核心机制的关键问题。**Label (标签)** 和 **Selector (选择器)** 是 Kubernetes 中用于组织、管理和选择资源的基本机制。它们共同协作，实现了 Kubernetes 强大的自动化和解耦能力。

---

## 🏷️ 1. Label（标签）是什么？

**Label** 是附加到 Kubernetes 对象（如 Pod、Node、Service、Deployment 等）上的 **键值对 (Key-Value pairs)**。

### 作用：组织和识别

* **识别属性：** Label 用于以对用户有意义的方式识别对象。
* **解耦：** 它们不直接耦合到核心系统，而是用于用户自定义的组织结构。
* **示例：**
    * **应用类型：** `app: frontend` 或 `app: database`
    * **环境：** `env: production` 或 `env: development`
    * **版本：** `version: v1.2.3`

**特点：**

* 一个对象可以有多个 Label。
* Label 可以在对象创建后随时添加或修改。

---

## 🔎 2. Selector（选择器）是什么？

**Selector** 是一种表达式，用于 **匹配** 具有特定 Label 的一组对象。它是 Kubernetes 自动化和控制循环工作的核心机制。

### 作用：定位和管理

Selector 的作用是告诉控制器（Controller）或 Service 应该管理或路由到哪些对象。

### 常见的 Selector 使用场景：

1.  **ReplicaSet/Deployment Selector:** 用于告诉控制器应该管理哪些 Pod（确保它们数量正确）。
2.  **Service Selector:** 用于告诉 Service 应该将客户端请求路由到哪些后端的 Pod。
3.  **Node Selector:** 用于限制 Pod 只能在具有特定 Label 的 Node 上调度。

**示例：**

一个 Service 的 Selector 可能是 `app: frontend`，这意味着它只会将流量路由到所有带有 `app: frontend` 标签的 Pod。

---

## 🔗 3. Label 和 Selector 的关系（核心）

**Label 和 Selector 之间的关系是“标识与选择”的关系。**

* **Label 负责标识 (Identity):** 它们是对象身上的“身份标签”。
* **Selector 负责选择 (Selection):** 它们是“查找条件”，根据 Label 去找对应的对象。

### 关系图示

| 资源 | 定义 Selector | 定义 Label | 核心功能 |
| :--- | :--- | :--- | :--- |
| **Deployment / ReplicaSet** | `spec.selector.matchLabels` | `spec.template.metadata.labels` | **管理 Pod：** ReplicaSet 使用 Selector 找到由它管理的 Pod，并确保数量等于 `replicas`。 |
| **Service** | `spec.selector` | 作用于 Pod | **流量路由：** Service 使用 Selector 找到后端健康的 Pod 列表，并将流量负载均衡到这些 Pod。 |

**关键的匹配原则：**

1.  **控制器和 Pod 模板：** 在定义像 `Deployment` 这样的控制器时，您必须确保 `spec.selector.matchLabels` 中定义的标签选择器，与 `spec.template.metadata.labels` 中定义的 Pod 标签**完全一致**。如果它们不匹配，控制器将无法找到或创建自己的 Pod。
2.  **Pod 和 Service：** Service 使用其 Selector 来查找所有匹配的 Pod，这些 Pod 成为 Service 的**端点 (Endpoints)**。

