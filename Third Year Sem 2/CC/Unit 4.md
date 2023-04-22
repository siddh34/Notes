# Unit 4 Ansible

## YAML

### Simple Example

```YAML
    name: Siddharth
    rollNo: 323054
    college: viit
```

### Comments

```YAML
    # This is YAML SCRIPT
```

### Objects

```YAML
    STUDENT1:
        name: Siddharth
        rollNo: 323054
        college: viit

    STUDENT2:
        _______
        _______
```

### LIST

```YAML
    # WAY 1 to write list

    STUDENT1:
        name: Siddharth
        rollNo: 323054
        college: viit
        Subjects:
            - AMD
            - CC
            - DAA
            - SDA
            - EEF
        
    # WAY 2 to write list
    
    STUDENT2:
        name: Siddharth
        rollNo: 323054
        college: viit
        Subjects: [ AMD, CC, DAA, SDA, EEF ]
```

### variables in yaml

#### Strings

```YAML
    # 1
    name: "Siddharth"
    # 2
    name2: 'Sidd'
    # 3
    name3: Siddharth
    # String pipe
    name4: |
        This is first line
        This is second line
        This is third line
    # Multiple lines are written but considered as single line
    name5: >
        This is first line
        This is second line
        This is third line
```

#### Numbers

```YAML
    num1: 23
    num2: 123.1
    num3: 0.1
```

#### Boolean

```YAML
    isTrue: true
    isFalse: No
    isFalse: off
```

#### Start & end

```YAML
    # Start
    _ _ _
    
    . . .
    # End
```

Sample Script

```YAML
    - STUDENT1:
        rollno: 23
        name: "Sidd"
        address:
            - Street: laxminagar
            - Area: Kondhwa
            - Pin: 411048
        Phone: [1234,5678]
    - STUDENT2:
        ____
        ____
        ____
```

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

## Roles

* Roles is a Directory Structure

* It is used when project becomes too big
