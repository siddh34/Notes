# DAA Lecture Notes

## Lecture 3

## Classifying Problems

1. P-Class

        i. Time complexity is O(n**k)
        ii. They are Tracktable Problems
        iii. This class contains many natural problems like:
                a. Calculating the greatest common divisor.
                b. Finding a maximum matching.
                c. Decision versions of linear programming.

2. NP-Class (Non-deterministic Polynomial Class)

        i. The solutions of the NP class are hard to find since they are being solved by a non-deterministic machine but the solutions are easy to verify
        ii. Problems of NP can be verified by a Turing machine in polynomial time
        iii. Examples
                a. Boolean Satisfiability Problem (SAT).
                b. Hamiltonian Path Problem.
                c. Graph coloring.

3. Co-NP Class

        i. Co-NP stands for the complement of NP Class
        ii. If a problem X is in NP, then its complement X’ is also is in CoNP.
        iii. For an NP and CoNP problem, there is no need to verify all the answers at once in polynomial time, there is a need to verify only one particular answer “yes” or “no” in polynomial time for a problem to be in NP or CoNP.
        iv. Examples
                a.To check prime number
                b. Integer Factorization

4. NP-hard class

        i. All NP-hard problems are not in NP. 
        ii. It takes a long time to check them. This means if a solution for an NP-hard problem is given then it takes a long time to check whether it is right or not
        iii. A problem A is in NP-hard if, for every problem L in NP, there exists a polynomial-time reduction from L to A
        iv. Example
                a. Halting problem
                b. Qualified Boolean formulas
                c. No Hamiltonian cycle

5. NP-complete class

        i. NP-complete problems are special as any problem in NP class can be transformed or reduced into NP-complete problems in polynomial time
        ii. If one could solve an NP-complete problem in polynomial time, then one could also solve any NP problem in polynomial time
        iii. A problem is NP-complete if it is both NP and NP-hard
        iv. Example
                a. Decision version of 0/1 Knapsack
                b. Hamiltonian Cycle
                c. Satisfiability
                d. Vertex cover

Complexity Class | Characteristic feature
------- | -------
P | Easily solvable in polynomial time.
NP | Yes, answers can be checked in polynomial time.
Co-NP | No, answers can be checked in polynomial time.
NP-hard | All NP-hard problems are not in NP and it takes a long time to check them.
NP-complete | A problem that is NP and NP-hard is NP-complete.

### Problem  Solving

Important **Steps** to solve problems

    1. Understanding the Problem Statement
    2. Figure Out Sample Inputs and Expected Outputs
    3. Divide the Problem Into Small Chunks
    4. Explore Important Existing Algorithms for Inspiration
    5. Write Pseudocode First
    6. Write Simple Code and Generalize It
    7. Try to Improve Your Algorithmic Creation
    8. Find a Suitable Data Structure
    9. Problem Solving via Design Patterns
    10. Practice Make a Developer Perfect
