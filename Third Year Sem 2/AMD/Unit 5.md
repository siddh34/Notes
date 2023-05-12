# Unit 5 Build Tools – GIT and Jenkins

## GIT

### Version Control System

1. Version Control Systems (VCS) have seen great improvements over the past few decades and some are better than others. VCS are sometimes known as SCM (Source Code Management) tools or RCS (Revision Control System)

2. One of the most popular VCS tools in use today is called Git. Git is a Distributed VCS, a category known as DVCS, more on that later

3. There are different types of VCS, such as Centralized VCS (CVCS) and Distributed VCS (DVCS). CVCS uses a central server to store all files and enables team collaboration, but it also has some drawbacks, such as dependency on network connectivity, single point of failure, and limited access control

4. Git is one of the most popular DVCS tools in use today. It is free and open source, and it has many features that make it powerful and versatile

5. Some of these features are

        1. Branching and merging: Git allows you to create multiple branches of your code, which are independent lines of development that can be switched between easily. You can also merge branches together to combine their changes or resolve conflicts.
        2. Staging area: Git has a special area called the staging area, where you can select which files or changes you want to commit (save) to the repository. This gives you more control and flexibility over your commits.
        3. Snapshots: Git stores your files as snapshots, not as differences. This means that every commit is a full picture of your project at that point in time, which makes it faster and more reliable23.
        4. Checksums: Git uses a mechanism called checksums to ensure the integrity and consistency of your data. Every file and commit is identified by a unique hash value that is calculated based on its content. This prevents any corruption or tampering of your data

6. These are some of the basic concepts of VCS and Git. I hope this helps you understand them better. If you want to learn more, you can check out some of the sources I used for this answer

### Basics commands

        git init: This command creates a new Git repository.
        git add: This command adds changes to the staging area.
        git commit: This command commits the changes in the staging area to the repository.
        git log: This command shows the history of commits in the repository.
        git branch: This command creates or lists branches in the repository.
        git checkout: This command switches to a different branch.
        git merge: This command merges two branches together.
        git push: This command pushes changes to the remote repository.
        git pull: This command pulls changes from the remote repository.

### Stage

* Modified: This means that you have changed the file but have not committed it to your database yet.

* Staged: This means that you have marked a modified file in its current version to go into your next commit snapshot.

* Committed: This means that the data is safely stored in your local database.

### Branch

* A branch in Git is a pointer to a specific commit in the project's history. When you create a new branch, you are creating a new pointer to the current commit. This allows you to work on different features or bug fixes without affecting the main branch

* For example, let's say you are working on a project and you want to add a new feature. You can create a new branch for this feature and start working on it. Once you are finished with the feature, you can merge it back into the main branch.

* This is a very powerful feature of Git and it allows you to work on multiple projects at the same time without getting them confused.

### Merge

* Git merge is a command that merges changes from one branch into another. This is useful when you have been working on a new feature or bug fix in a separate branch, and you want to incorporate those changes into the main branch

* The Order of commands

        git checkout master
        git merge

* When you merge two branches, Git will try to automatically resolve any conflicts that occur. If there are any conflicts, you will need to resolve them manually before you can continue.

* Once all of the conflicts have been resolved, Git will merge the two branches together. The new commit will have two parents, one for each of the branches that were merged.

* Git merge is a very powerful tool that can help you collaborate with others on projects. It is also a very useful tool for managing your own work

### Remote

* A remote in Git is a repository that is not local to your computer. It can be a public repository, such as the GitHub repository for the Linux kernel, or a private repository that is hosted on your company's internal server

      Working -> Staging area -> Local repo -> remote repo

* When you clone a repository, Git creates a remote called "origin" that points to the original repository. You can then use the git fetch and git push commands to interact with the remote repository.

* The git fetch command copies the changes from the remote repository to your local repository. This allows you to stay up-to-date with the latest changes to the project.

* The git push command copies the changes from your local repository to the remote repository. This allows you to share your changes with other developers.

## Jenkins & Continuous Integration

* Continuous Integration (CI) is a process of integrating code changes from multiple developers in a single project many times. The software is tested immediately after a code commit

* Jenkins is used for continuous integration

* Jenkins architecture

  ![Img](./Image/jetkins%201.png)

* About jenkins

      1.  Jenkins is an open-source Continuous Integration server written in Java that can automate build and test tasks

      2.  Jenkins supports the complete development life cycle of software from building, testing, documenting, deploying, and more

* Jenkins can be easily set up and configured via its web interface, and it has hundreds of plugins to support various tools and stages of the software development life cycle

### Plugins

* ANT Plugin

    The Ant Plugin for Jenkins is a free and open-source plugin that allows you to use Apache Ant to build your software projects

* Maven Plugin

    The plugin allows you to build, test, and deploy your Maven projects from Jenkins

* Github Plugin

    It is used for github integration with jenkins

* Credential Plugin

    Organize credentials across domains and maintains password secret once.

### Various scenarios of Building Delivery Pipeline

1. Manual delivery: This is the simplest scenario, and it involves manually building and deploying your code. This can be a good option for small projects with a limited team

2. Continuous integration (CI): CI is a more automated approach to delivery. With CI, your code is built and tested automatically whenever you make a change. This can help to identify and fix bugs early on, and it can also speed up the delivery process

3. Continuous integration (CI): CI is a more automated approach to delivery. With CI, your code is built and tested automatically whenever you make a change. This can help to identify and fix bugs early on, and it can also speed up the delivery process

4. Continuous integration (CI): CI is a more automated approach to delivery. With CI, your code is built and tested automatically whenever you make a change. This can help to identify and fix bugs early on, and it can also speed up the delivery process

## BUILD IN JENKINS

1. Firstly configure jenkins properly

2. Then click on build button to build the project

Note: There can be multiple steps for configuring jenkins

## Test Automation

* Test automation is the use of software to execute tests automatically, without human intervention

* They save time & money

* We can catch bugs easily & often

* Some of the most popular tools include

        1. Selenium: A free and open-source tool for automating web applications.
        2. Robot Framework: A generic test automation framework that can be used to automate a variety of different types of tests.
        3. JUnit: A unit testing framework for Java.
        4. NUnit: A unit testing framework for .NET.
        5. TestComplete: A commercial test automation tool from SmartBear.
        6. Silk Test: A commercial test automation tool from Borland.
        7. Ranorex: A commercial test automation tool from Ranorex

Note:

* The best tool for you will depend on your specific needs and requirements

* For starters selenium & Robot framework are the best

## Security in jenkins

* Security in Jenkins is the process of ensuring that only authorized users can access and perform operations on the Jenkins server and its projects

* The Two Aspects of security in jenkins

        1. Access control, which ensures users are authenticated when accessing Jenkins and their activities are authorized.
        2. Data protection, which ensures sensitive data such as passwords and keys are encrypted and secured

* To configure security in Jenkins, you need to enable security option in the global configuration and choose a security realm and an authorization strategy

* A security realm determines how Jenkins authenticates users, such as using its own user database, LDAP, or other methods.

* An authorization strategy determines how Jenkins authorizes users, such as using matrix-based security, role-based strategy, or other plugins

Note:  You should always enable security for any non-local Jenkins environment and follow the best practices for managing security

## Notification system of jenkins

* Notification system in Jenkins is a feature that allows you to send email notifications to the team members or other stakeholders about the status of the build and test results

* There are two ways to configure email notifications in Jenkins

        1. Using Email Extension Plugin: This plugin lets you configure every aspect of email notifications, such as when to send the email, who receives it, and what the email says

        2. Using Default Email Notifier: This comes with Jenkins by default. It has a default message consisting of a build number and status. You can also specify the recipients and the trigger conditions for sending the email

Note:

1. To configure email notifications in Jenkins, you need to enable and set up an SMTP server in the global configuration under the E-mail Notification section

2. You also need to add a post-build action in your project configuration to send an email notification after the build is completed
