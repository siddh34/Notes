# Docker

What is container?

    Min Environment that is used to run application is called container

    Proper def --> Running instance of image is called container

Note:

* we can write our own **images**

* Images are layered

## Virtualization vs Containerization

| Virtualization | Containerization |
| ---------------| -----------------|
| Heavy Architecture | light architecture |
| Guest OS concept | No Guest OS concept |
| Runs just about any operating system inside the virtual machine | Runs on the same operating system version as the host |
| Deploy individual VMs by using Hypervisor software | Deploy individual containers by using Docker or deploy multiple containers by using an orchestrator such as Kubernetes |
| Virtual machine load balancing is done by running VMs in other servers in a failover cluster | An orchestrator can automatically start or stop containers on cluster nodes to manage changes in load and availability |

### Virtualization Concepts

#### Virtualization

* Virtualization is a technique that allows you to create a virtual version of something like computer hardware, operating system, storage device, or network resource

* Virtualization uses software to create an abstraction layer over the physical hardware that enables you to divide it into multiple virtual machines (VMs)

* Each VM can run its own operating system and applications independently from the others, even though they share the same underlying hardware

* Virtualization also brings benefits such as resource efficiency, easier management, scalability, and reliability

Note: Virtualization is the foundation of cloud computing

#### Hypervisor

* A hypervisor is a type of software, firmware, or hardware that creates and runs virtual machines (VMs)

* A hypervisor allows you to run multiple operating systems on a single physical machine by creating an abstraction layer over the hardware and allocating resources to each VM

* A hypervisor is also known as a virtual machine monitor (VMM) or a virtualizer

* There are two types of hypervisors: type-1 and type-2

* Type-1 hypervisors: run directly on the host machine’s hardware and are also called native or bare-metal hypervisors. Examples of type-1 hypervisors include VMware ESXi, Citrix XenServer, and Microsoft Hyper-V

* Type-2 hypervisors: run on a host operating system and are also called hosted hypervisors. Examples of type-2 hypervisors include VMware Player, Parallels Desktop, and VirtualBox

Note:

        Hypervisors are essential for virtualization and cloud computing, as they enable efficient utilization of hardware resources, easier management of multiple operating systems, scalability, and reliability

## Registry &  Dockerhut

* Registry is private

* Dockerhut is public

## Local Vs Docker

* Local goes on local host i.e global environment

* Docker run on it's specific environment

## Docker Engine

* Docker Engine is an open source containerization technology for building and containerizing your applications

* It acts as a client-server application with a server, a daemon process, APIs, and a command line interface

* It creates and manages Docker objects, such as images, containers, networks, and volumes

* It runs on various Linux and Windows Server operating systems

Note: In order to user docker engine we need to install docker desktop for windows

## Docker Architecture

![IMG](./Images/docker%20architecture.png)

### The Docker daemon

The Docker daemon (dockerd) listens for Docker API requests and manages Docker objects such as images, containers, networks, and volumes. A daemon can also communicate with other daemons to manage Docker services.

### The Docker client (docker)

The Docker client is the primary way that many Docker users interact with Docker. When you use commands such as docker run, the client sends these commands to dockerd, which carries them out. The docker command uses the Docker API. The Docker client can communicate with more than one daemon.

### Docker Desktop

Docker Desktop is an easy-to-install application for your Mac, Windows or Linux environment that enables you to build and share containerized applications and microservices. Docker Desktop includes the Docker daemon (dockerd), the Docker client (docker), Docker Compose, Docker Content Trust, Kubernetes, and Credential Helper. For more information, see Docker Desktop.

### Docker registries

A Docker registry stores Docker images. Docker Hub is a public registry that anyone can use, and Docker is configured to look for images on Docker Hub by default. You can even run your own private registry.

When you use the docker pull or docker run commands, the required images are pulled from your configured registry. When you use the docker push command, your image is pushed to your configured registry.

### Docker objects

When you use Docker, you are creating and using images, containers, networks, volumes, plugins, and other objects. This section is a brief overview of some of those objects.

### Images

An image is a read-only template with instructions for creating a Docker container. Often, an image is based on another image, with some additional customization. For example, you may build an image which is based on the ubuntu image, but installs the Apache web server and your application, as well as the configuration details needed to make your application run

### Containers

A container is a runnable instance of an image. You can create, start, stop, move, or delete a container using the Docker API or CLI. You can connect a container to one or more networks, attach storage to it, or even create a new image based on its current state

## Container Management

Basic container operations are the commands that can be used to work with containers, such as creating, running, stopping, removing, and listing them

* docker create [IMAGE_NAME]: This command creates a container from an image without running it

* docker run [IMAGE_NAME]: This command creates and runs a container from an image

* docker start [CONTAINER_NAME]: This command starts a stopped container.

* docker stop [CONTAINER_NAME]: This command stops a running container.

* docker restart [CONTAINER_NAME]: This command restarts a running or stopped container.

* docker pause [CONTAINER_NAME]: This command pauses the processes inside a running container.

* docker unpause [CONTAINER_NAME]: This command resumes the processes inside a paused container.

* docker ps: This command lists the running containers.

* docker rm [CONTAINER_NAME]: This command removes a container from the system

These are some of the basic container operations that can be performed using Docker

## Docker storage & volumn

* Docker storage consists of a storage driver and a volume driver

### The Drivers

* The storage driver controls how the images and containers are stored and managed on the host machine. It provides a union file system that layers the read-only images and the writable container layers. There are different types of storage drivers, such as overlay, aufs, devicemapper, etc

* The volume driver controls how the volumes are created and mounted into the containers. Volumes are the preferred way to persist data that is generated by and used by containers

Note: Volumes are stored in a part of the host file system that is managed by Docker, and they can be shared among multiple containers

### Docker volumns

* Docker volumes are directories or files that are mounted into a container to store persistent or shared data

* Volumes have several advantages over storing data in the container’s writable layer or using bind mounts

* Some more info about docker volumes

        Volumes are easier to back up or migrate than bind mounts
        Volumes can be managed using Docker CLI commands or the Docker API
        Volumes work on both Linux and Windows containers
        Volumes can be more safely shared among multiple containers
        Volume drivers let you store volumes on remote hosts or cloud providers, to encrypt the contents of volumes, or to add other functionality
        New volumes can have their content pre-populated by a container

Note: To mount a volume into a container, you can use the --mount or -v flag with the docker run command. To list, inspect, or remove volumes, you can use the docker volume ls, docker volume inspect, or docker volume rm commands respectively

## Docker compose

* Docker Compose is used to run a multi-container application from a YAML file. A YAML file is a text file that defines the services, networks, volumes, and other components of an application. It specifies how to build or pull the images, how to link and scale the services, how to mount the volumes, and other settings for the application

* For example, docker compose up will create and start all the services defined in the docker-compose.yml file in the current directory

* Docker Compose can build multiple images and run multiple containers at once, while Docker build can only build one image at a time.

* Docker Compose also simplifies the development and deployment of multi-container applications by allowing you to define them in a declarative way

## Kubernetes

![IMG](./Images/kubernetes%20logo.png)

* Kubernetes is an open-source system for automating deployment, scaling, and management of containerized applications

* It groups containers that make up an application into logical units called pods for easy management and discovery

* Kubernetes builds upon 15 years of experience of running production workloads at Google, combined with best-of-breed ideas and practices from the community

Kubernetes has several features that make it effective for managing containerized applications. Some of these features are

* It supports service discovery and load balancing to distribute traffic among pods and expose them to the external world

* It supports storage orchestration to mount different types of storage systems to pods

* It supports automatic bin packing to optimize the use of resources across nodes

* It supports self-healing to restart failed containers, replace unhealthy pods, and reschedule pods when nodes die

* It supports secret and configuration management to store and manage sensitive information such as passwords and keys

* It supports horizontal scaling to increase or decrease the number of pods based on demand or custom metrics

* It supports batch execution to run batch and cron jobs

* It supports declarative configuration to describe the desired state of the application using YAML or JSON files

### Kubernetes Architecture

![IMG](./Images/kube%20arch.png)

Kubernetes architecture is a client-server design that consists of the following components

* Control plane: It is the brain of the cluster that manages the state and configuration of the cluster. It consists of several components, such as

        1. API server: It is the entry point for all the REST commands used to control the cluster. It validates and processes the requests and updates the cluster state accordingly

        2. Scheduler: It is responsible for assigning pods to nodes based on resource availability, constraints, affinity, anti-affinity, etc

        3. Controller manager: It runs various controllers that handle different aspects of the cluster, such as node controller, replication controller, endpoint controller, service account controller, etc

        4. etcd: It is a distributed key-value store that stores the cluster data in a consistent and reliable way. It acts as the source of truth for the cluster state

* Nodes: They are the worker machines that run the containers and pods. They consist of several components, such as

        1. Kubelet: It is an agent that runs on each node and communicates with the API server. It manages the pods and containers running on the node

        2. Container runtime: It is the software that runs and manages the containers, such as Docker, containerd, CRI-O, etc

        3. Kube-proxy: It is a network proxy that maintains the network rules and enables network communication among pods and services

* Pods: They are the **smallest and simplest units of deployment in Kubernetes**. They are a **group of one or more containers that share the same network namespace, IP address, volumes, etc**. Pods can be created directly or through higher-level abstractions, such as deployments, statefulsets, daemonsets, etc

* Services: They are an abstraction that defines a logical set of pods and a policy to access them. They provide a stable and reliable way to communicate with pods without knowing their exact locations or IP addresses. Services can be exposed internally within the cluster or externally to the outside world

* ngress: It is an API object that manages external access to the services in a cluster. It provides load balancing, SSL termination, name-based virtual hosting, etc1. Ingress requires an ingress controller to function properly

### Application Lifecycle Management (ALM)

* ALM using Kubernetes is the process of managing the development, deployment, and maintenance of applications running on Kubernetes clusters

* It involves following aspects

        1. Application definition: This is the stage where you define the components and configuration of your application using Kubernetes objects, such as pods, services, deployments, configmaps, secrets, etc. You can use YAML or JSON files to describe your application manifest

        2. Application delivery: This is the stage where you package and distribute your application to Kubernetes clusters. You can use tools such as Docker or Buildah to build and push your container images to a registry

        3. Application management: This is the stage where you monitor and update your application running on Kubernetes clusters. You can use tools such as Prometheus, Grafana, or Jaeger to collect and visualize metrics, logs, and traces of your application. You can use tools such as Kubernetes Dashboard, Lens, or Octant to manage and troubleshoot your application resources

* Steps for Application Lifecycle Management using Kubernetes on app store

        1. Create a customized role and two users

        2. Upload and submit an application

        3. Release the application

        4. Release the application to the App Store

        5. Create an application category

        6. Add a new version

        7. Upgrade an application

        8. Suspend an application

## Security in Kubernetes

Security of Kubernetes is the process of ensuring that the Kubernetes clusters, pods, containers, and applications are protected from unauthorized access, malicious attacks, and data breaches

* Cluster security: This is the process of securing the Kubernetes control plane and nodes, as well as the etcd database that stores the cluster state. Cluster security includes configuring role-based access control (RBAC), encryption, authentication, authorization, network policies, firewalls, and audit logging

* Pod security: This is the process of securing the pods that run the containers and applications. Pod security includes enforcing pod security standards, pod security policies, service accounts, secrets, and security contexts

* Container security: This is the process of securing the container images and runtimes that are used by the pods. Container security includes scanning and signing images, using trusted registries, applying resource limits and quotas, isolating containers, and monitoring container activity

* Application security: This is the process of securing the application code and data that are running inside the containers. Application security includes following secure coding practices, encrypting data at rest and in transit, implementing secure communication protocols, and using application security tools such as web application firewalls (WAFs), intrusion detection systems (IDSs), and vulnerability scanners

### What we can do to sercure our kubernetes

1. Enable Kubernetes Role-Based Access Control (RBAC)

2. Use Third-Party Authentication for API Server

3. Protect etcd with TLS, Firewall and Encryption

4. Isolate Kubernetes Nodes

5. Monitor Network Traffic to Limit Communications

6. Use Process Whitelisting

7. Turn on Audit Logging

8. Keep Kubernetes Version Up to Date

9. Lock Down Kubelet

## Helm

* Helm helps you manage Kubernetes applications — Helm Charts help you define, install, and upgrade even the most complex Kubernetes application

* Charts are easy to create, version, share, and publish — so start using Helm and stop the copy-and-paste

* Long story short helm is package manager for kubernetes

* Helm has several features that make it effective for managing Kubernetes applications

        1. It supports declarative configuration to describe the desired state of the application using YAML or JSON files
        2. It supports dependency management to automatically install or update the dependencies of a chart
        3. It supports release management to track the history and status of each release of an application
        4. It supports templating to dynamically generate the configuration based on variables and functions
        5. It supports hooks to execute custom actions before or after installation, upgrade, deletion, or rollback of a chart
        6. It supports repositories to store and distribute charts publicly or privately

Note: Helm can run on various platforms, such as Linux, macOS, Windows, and Docker. It can also integrate with various tools and services, such as Kubernetes Dashboard, Helm Operator, Helmfile, etc
