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
| 	Deploy individual VMs by using Hypervisor software | Deploy individual containers by using Docker or deploy multiple containers by using an orchestrator such as Kubernetes |
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
