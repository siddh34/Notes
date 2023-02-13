# Unit 2 **AWS**

Cloud has

1. Services

        It can be 
            i. Software as service
            ii. Platform as service
            iii. Infrastructure as service

2. Deploy models

        a. They can be 
            i. Public
            ii. Private
            iii. Hybrid (Public + Private)
            iv. Community

3. 5-Essential characteristics

        a. On demand useage
        b. Ubiquitoues access
        c. Multitenancy (and resource pooling)
        d. Elasticity
        e. Measured usage
        f. Resiliency (Robust to its own failure)

## On-Premise & Cloud

On-Premises means we own the server

Cloud means someone else owns the server

## Az's

Availability zones are multiple zones where servers are located. So that one crashes one can work

if US-East is one region then AZ's will be us-east1

## IAM

        1. IAM has user, group and roles
        2. Specific roles have specific access for certain time

## NAT

        1. IPs are not exposed to outside world
        2. NAT always should be in public

## VPC

        1. Region based service
        2. According to need we create VPC

## SG

        1. Instance level
        2. Stateful

Note: Inbound: Goes towards to machine, Outbound: Goes away from the machine

## NACAL

        1. Subnet level rules
        2. Stateless

## VPC paring

        1. Comunicates between VPCs

Note: AWS has 5 address reserved

## S3

        1. Storage
        2. It uses cloudfront (Edge location) & cloudformation (But we will be using Teraform)

## Important cloud service

* Compute (EC2 and lambda)

* Storage (EFS, EBS, S3)

* N/W (VPC, SH)

* Database

## Lambda service

        a. It is serverless service
        b. Server's cost is saved 

## Case Study

### Cloud architecture

![Img 1](./Images/architecture.jpg)

1. Make a VPC

2. Create subnets

3. Create route tables. Link route to subnets

4. Create security groups

5. Create instances

6. Create a common SG to be assigned to both

7. Create load balancer and Target Group

8. Add rules HTTP to SG
