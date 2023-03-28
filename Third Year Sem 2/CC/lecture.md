# Lecture 7

## Unit 4 Ansible

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
        This is third linec
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
