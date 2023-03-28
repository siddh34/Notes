# Unit 4 Intractable Problems and NP-Completeness

Algorithm can be divided into two parts

1. Ploynomial time

        1) Linear Search
        2) Binary Search
        3) Insertion Sort
        4) Merge Sort

2. Exponential time / Non ploynomial time

        1) TSP
        2) GRAPH COLORING
        3) Sudoku
        4) Scheduling

## P Class Problem

A problem which can be solved in ploynomial time is called the P class problem

## NP Class Problem

* A problem which cannot be solved in ploynomial time but it is verified in ploynomial time is called the NP class problem

* Example SUDOKU

        +-------+-------+-------+
        | 6 3 . | . 7 . | . . . |
        | . 9 . | . . 6 | 3 7 . |
        | 8 . . | 9 . . | . 6 2 |
        +-------+-------+-------+
        | . 6 . | 2 8 9 | 1 . . |
        | 3 . 9 | . 6 . | 7 . 8 |
        | . . 1 | 7 3 4 | . 9 . |
        +-------+-------+-------+
        | 7 4 . | . . 8 | . . 6 |
        | . 2 6 | 6 . . | . 8 . |
        | . . . | . 9 . | . 4 7 |
        +-------+-------+-------+

## Deterministic algorithm

    Problems where we know its every steps

## Non Deterministic algorithm

    1. Problems where we don't know its every steps

    2. Example

```Python
        TYC_SEARCH(A,N,KEY):
            i = choice()

            if(i == key)
                print(i)
            
            print(0)
```

## P & NP CLASS + NP HARD & NP Complete

    +---------------------+
    |                     |
    |                     |    +-----------------+
    |                     |    |                 |
    |                     |    |                 |
    |          NP         |    |                 |
    |                     |    |                 |
    |                     |    |                 |
    |                     |    |                 |
    +---------------------+    |                 |
    |          P          |    |                 |
    +---------------------+    |                 |
                               |                 |
                               |   NPcomplete    |
                               |                 |  
                               |                 |
                               +-----------------+ 
                               |   NP-hard       |
                               +-----------------+

Exact Diagram

![Img](./Images/np.png)

1. Inside P tractable problems are there

2. Inside NP non tractable problems are there

3. P is the class of problems that can be solved by a deterministic machine in polynomial time

4. NP is the class of problems that can be solved by a non-deterministic machine in polynomial time, or equivalently, verified by a deterministic machine in polynomial time given a certificate or a hint.

5. **NP-complete is the class of problems that are both in NP and as hard as any problem in NP**, meaning that **any problem in NP can be reduced to them in polynomial time**. Example eulers graph

6. **NP-hard is the class of problems that are at least as hard as any problem in NP**, meaning that **any problem in NP can be reduced to them in polynomial time, but they may or may not be in NP themselves.** Example optimization problem

The diagram also shows two possible scenarios for the relationship between P and NP

    1. The left side assumes that P ≠ NP, meaning that there are some problems in NP that cannot be solved by a deterministic machine in polynomial time. This is the most widely believed conjecture, but it has not been proven or disproven yet.
    2. The right side assumes that P = NP, meaning that there are no problems in NP that cannot be solved by a deterministic machine in polynomial time. This would imply that all problems in NP are also in P, and that all problems in NP-complete are also in P. This would have profound implications for cryptography, optimization, and artificial intelligence, but it is considered very unlikely by most experts.

## More on NP HARD & NP Complete

    + - +         + - +
    + A + - - - > + B -
    + - + - - - - + - +

1. A & B are two problem A reduces to problem B
2. There is a way to solve A by deterministic algo that solve B in ploynomial time
