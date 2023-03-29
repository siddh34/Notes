# Lecture 8

## Ansible

* Configuration Management Tool

* It has two things Ansible tower & Ansible Galaxy

### Ansible workflow

![IMG](./Images/ansi.png)

* It is a agentless tool

* Host & master can be same

### Terminologies

1. Ad-boc command

        Single commands

2. Playbook

        1. Collection of multiple commands
        2. One playbook cantains of many plays

    ![IMG](./Images/playbook.png)

3. Modules

        1. Certains commands but not the collection

4. Roles

        1. Well Organized structure of files

### Ansible workflow example

Note: before starting you need to have another machine whether aws instance or another user on ubuntu

1. Make a folder

2. Take sudo access

3. Make SSH keys & copy them from master to target

4. Paste the keys in system files of target

5. Write ansible playbook for the task

6. Run the playbook
