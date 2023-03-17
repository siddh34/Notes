# Unit 2 Architectural Design

## Architecture

Architecture is nothing but a blue print that defines a system

## Software Architecture

    a. It is blueprint for the system
    b. Abstraction to manage system and establish communication and co-ordination among components
    c. It refers to the fundamental structure of the software and the disciplines to create such software

Example of whatsapp functions

![Img 1](./Images/architecture.jpg)

Note: **All software architecture are software design but not all software design are software architecture**

    d. Software architecture affects quality of software. They are directly proportional
    e. Why use software architecture?
        i. It helps in real world complex world
        ii We can distrubute work between team members
        iii. Helps in understanding the system
    f. Users of software Architecture
        i. Project Managers
        ii. Software Dev
        iii. Tester
        iv. Anyone who wants to make an improvement by looking at architecture

## Software Design

It is **mechanism to transform user requirements into something useful**

Objectives

    i. Correctness
    ii. Completeness
    iii. Efficient

## Architectural Design vs Software Design

| Software Design | Architectural Design |
| - | - |
| Sub modules are present | Only overall model is designed |
| Implmentation is there somewhat | Implimentation is hidden |

## Architectural Design

* System strucuring

* Control Modelling

* Modular decomposition

## Subsystem & modules

* Sub system: It is a system own its own doesn't depend on other sub system

* Module: It is a component which provides services but it cannot provide services

## Architectural Design Process

1. Understand the problem

2. Identify design elements

3. Evaluate the Design architecture

4. Transform the architecture

### Types of Architectures

* Bussiness architecture: Design the bussiness strategy

* Application architecture: servers as a blueprint for individual application system

* Information technology architecture: Define hardware and software for that system

## Architecture Modules

* It involves high level structure of software system abstraction by using decomposition

* Its parts are

        a. UML
            i. Pictorial language use to make blueprints
            ii. Divided into two sub categories
                I. Structural (class diagram,object diagram,component diagram, Package diagram, Deployment diagram)
                II. Behavioural (Sequence diagram, State diagram, Activity diagram)

## Architectural View Model

* It is used to describe the system from the viewpoint of different stakeholders

* The 4 + 1 view model was designed by philippe to describe the architecture of software

* It is a multiple view model

### Types of views

1. Logical view

    a. Shows the component (object) or system as well as their interaction

    b. Viewer are end-users, analyst

    c. Considers functional requirements

    d. UML diagram (class, state, object, communication diagram)

2. Process

    a. Shows process and how processes communicate

    b. Integrators & developers are viewers

    c. Considers non functional requirements

    d. Activity diagram is drawn

3. Development

    a. Gives abuilding block of system and describe static organization system modules

4. Physical

    a. shows installation, configuration of software

5. Scenario

    a. shows design is complete by performing validation

![Img 2](./Images/types%20of%20views.jpg)

## ADL (Architecture Description language)

* It provides syntax and semantics for defining architecture of software

* It defines interfaces between components

## Software Architecture Styles

* Types

    a. Data Centered architecture

        i. It has two distinct components
            I. A central datastructure
            II. A collection of client software
        ii. Main purpose is to achieve integrality of data
        iii. Processes are individually executed by client components
        iv. Stored data is accessed in order to perform operations on it
        v. It adds scalability & supports modification
        vi. Hospital management system is perfect example of it

        I. Blackboard Architecture Style

            i.  provides Scalibity which provides ease to update knowledge source
            ii. Supports reusablity of knowledge source
            iii. Example
    ![Img 3](./Images/blackboard.jpg)

    b. Data flow architecture

        i. It is applied when input data is converted into a series of manipulative components into output data
        ii. It's types
            I. Batch sequential (Provides simple division on subsystem only problem is low throughtput)
            II. Pipe and filter architecture (It transforms the data stream, processes it and writes the transformed data stream over a pipe for next filter to process. Has two types passive and active filter)

    c. Logical architecture

    d. Call & Return architecture

## Distributed system architecture

* Components are present on different platforms & several components can co-operate with one another over a communication network in order to achieve a specific objective objective or goal

### Parallel & Distributed system

| Parallel | Distributed |
| - | - |
| Shared memory | Separate memory |
| Communication via shared memory | Communication via messages |

## Clint server architecture

Client: The one who requests

Server: It receives the request & replies the client

Middlewares are in between client

There are different types of client models

Thick/fat client models

    Server is the incharge of data

Thin client models

    Applications processing & data management is carried out by server

## DBMS Architecture

1st-tier

* The simple architecture is client server & database

2nd-tier

* Based on client server architecture application directly interact with database

3rd-tier

* Contains presentation layer, application layer & database

* It is more scalable

## RPC ( Remote Procedure Call )

RPC example is suppose there is a program run on one computer & it calls the function which is on another computer

## CORBA

* Distributed object based system

* Provides inter-operability

* CORBA Architecture

  ![Img](./Images/CORBA.png)

* Communication takes place in IDL langauge here

* Communication is between client & server!

## Broker

* It is responsible for co-ordinating request

## SOA ( Service Oriented Architecture )

* SOA combines large number of facilities from existing services to form application

* It is like a service mergering platform

* It is a blackbox for its consumers, meaning the consumer does not have to be aware of service's inner working

  ![Img](./Images/SOA.png)
