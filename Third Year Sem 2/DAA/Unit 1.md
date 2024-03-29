# DAA

## Unit 1 Introduction

Asymptotic Notation

    1. Without execution the time and space complexity of an algorithm is calculated using asymptotic notations
    2. Graphs can be drawn where time vs no of inputs can be taken into consideration
    3. Types 
        a. Big O notation O(n)
            --> By using the Big O notation hard bound can be understood (Upper bound)
            -->  it gives the worst-case complexity of an algorithm
        b. Omega notation Ω(n)
            --> Lower bound is determined
            --> it provides the best case complexity of an algorithm
        c. Big theta notation θ(n)
            --> Determine whether our value is in range i.e upper bound and lower bound
            --> it is used for analyzing the average-case complexity of an algorithm

Example O(n)

![Img 1](./Images/Daa%20lec%201%20ph%201.jpg)

f(n) <= c * g(n)

Constraints:

c > 0

n > n0

n0 >= 0

Equations:

    Suppose,
    f(n) = 2n**2 + n
    g(n) = n**2

    f(n) <= c*g(n)
    2(n**2) + n <= C*(n**2)

    n <= 0

    2(n**2) + n <= 3(n**2)
    n <= (n**2)
    1 <= n

Example Ω(n)

![Img 2](./Images/big%20omega.jpg)

    Suppose that
    C = 2
    2n*n + n >= c*n*n
    n >= 2n*n - 2n*n
    n >= 0

    Thus lower bound is determined by Ω(n)

Example Big theta θ(n)

![Img 3](./Images/big%20theta.jpg)

    C1*g(n) < f(n) < C2*g(n)

Note: *Q1. Describe Asymptotic Notation in brief*

Avg case Formula: (n+1)/2

## Searching algorithms

1. For Linear search

        i. Best case complexity is 1 (const) Ω(1)
        ii. Average case θ(n)
        iii.  Worst case O(n)

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

### Classification of Time Complexities

1. O(1) – Constant Time Complexity

        It does not matter, how many input elements a problem have, it takes constant number of steps to solve the problem

2. O(log n) – Logarithmic Time complexity

        In every step, halves the input size in logarithmic algorithm, log2 n is equals to the number of times n must be divided by 2 to get 1.

        Let us take an array with 16 elements input size, that is - log2 16

        step 1: 16/2 = 8 will become input size

        step 2: 8/2 = 4 will become input size

        step 3: 4/2 =2 will become input size

        step 4: 2/2 =1 calculation completed.

        The calculation will be performed till we get a value 1.

3. O(n) = Linear Complexity

        The number of steps and time required to solve a problem is based on input size. If you want to print a statement for n number of times, it is a linear complexity. Linear Search is an example for Linear Time Complexity

4. O(n log n) - (n * log n) complexity

        Divide and Conquer algorithms are generally considered under n log n time complexity. 

5. O(n^2) – Quadratic time complexity

        If we use nested loop, that means a loop with in an another loop, is a quadratic complexity.

        Outer loop runs n number of times, inner loop runs n*n number of times, that is O(n2).

6. O(n^n) – A n complexity

        In quadratic algorithm, we used two nested loops. In cubic algorithm we use n nested loops.

7. O(2^n) – Subset of input elements.

        The algorithm must run through all possible subsets of given input.

        Ex:

        {A, B, C} – possibilities of subsets are 2^3

        { }, {A}, {B}, {C}, {A,B}, {A, C}, {B,C}, {A,B,C}

8. O(n!) – Factorial complexity

        Example All permutations of input elements.

## Divide and conquer

Concepts are broken into 2 parts from each problem related to the problem statement itself.

    Suppose

    n = 2^k

    In first iteration we divide it as n = 2^(n-1)

    In second iteration we divide it as n = 2^(n-2)

    In third iteration we divide it as n = 2^(n-3)

    Then for combining we also need time of

    F(n) = (2^3) * (2^(n-3)) + k (time required for combining the problem)

Simple problem

    T(n) = T(n/2) + T(n/2) + n

    T(n) = 2 * T(n/2) + n

    also T(n/2) = 2 * T(n/4) + n/2

    by Substituition 

    T(n) = 2[2*T(n/2) + n/2 ] + n

    T(n) = 4T(n/4) + 2n. 

we can expand it so on

    Finally it would look like T(n) = nT(1) + kn

    T(n) = k(n)

why divide and conquer?

	1. Easy to use
	2. Solves problem in ease

## Analysis of merge sort

A merge sort consists of several passes over the input. The first pass merges segments of size 1, the second merges segments of size 2, and the i th pass merges segments of size 2i-1. Thus, the total number of passes is [log2n]. As merge showed, we can merge two sorted segments in linear time, which means that each pass takes O(n) time. Since there are [log2n] passes, the total computing time is O(nlogn).

### Merge Sort Working Process

        Think of it as a recursive algorithm continuously splits the array in half until it cannot be further divided. This means that if the array becomes empty or has only one element left, the dividing will stop, i.e. it is the base case to stop the recursion. If the array has multiple elements, split the array into halves and recursively invoke the merge sort on each of the halves. Finally, when both halves are sorted, the merge operation is applied. Merge operation is the process of taking two smaller sorted arrays and combining them to eventually make a larger one

![Img2](./Images/mergeSort.jpg)

## Questions

1. State whether the following function is correct or incorrect.

        a. 3n + 2 = O(n) (Remember the graph of O(n))
           Solution a: 
                As n >= n0
                f(n) = Og(n)
                f(n) <= C * g(n)
                f(n) = 3n + 2
                g(n) = n
                by putting n = 1 f(n) will be 5
                so g(n) = C * n
                as n >= n0 so C should be 5
                as n's value it can be >= 1 in order for the statement f(n) <= C * g(n) to be true.
                Similarly we can also check for n = 2, f(n) will be 8 and g(n) will be 10 which is exactly our condition

        b. 100n + 6 = O(n)
           Solution b:
                As n >= n0
                f(n) = Og(n)
                f(n) <= C * g(n)
                f(n) = 100n + 6
                g(n) = n
                putting n = 1
                f(n) = 106
                so C = 106
                Checking for n = 2
                f(n) = 206 and g(n) = 212
                so C = 106 and n >= 1 so that will statisfy our condition f(n) <= C * g(n)

        c. 10(n^2) + 4n + 2 = O(n^2) 
           Solution c:
                As n >= n0
                f(n^2) = Og(n^2)
                f(n^2) <= C * g(n^2)
                f(n^2) = 10(n^2) + 4n + 2
                g(n^2) = n^2
                lets say n = 1 in f(n^2)
                f(1) = 10 + 4 + 2 = 16
                so C = 16
                Checking for n = 2
                f(4) = 40 + 16 + 2 = 58
                g(4) = 16 * 4 = 64
                so C = 16 and n >= 1 will statisfy our condition f(n^2) <= C * g(n^2)

## Master's Theorem

        Remember the equation T(n) = aT(n/b) + f(n)

        where a >= 1 & b > 1

        Solution is T(n) = n^(log a to the base b) * U(n)

        U(n) depends on h(n)

        where h(n) = f(n)/ (n^log a to the base b)

        Relation between U(n) & h(n)

        if h(n) then U(n)

          n^r, r > 0 then U(n) =  O(n^r)

          n^r, r < 0 then U(n) = O(1)

          (log n)^i, i >= 0 then U(n) = ((log n)^(i+1))/(i+1)

        Note: r is the power of h(n) function4

        Once U(n) is found then substitute it in T(n) formula

Example

        T(n) = 8 T (n/2) + n log n

        a >= 1 & b > 1
        8 >= 1 & 2 > 1

        so we can use masters theorem here

        T(n) = n^(log 8 to the base 2) + U(n)

        T(n) = n^3 + U(n)

        so h(n) = f(n)/n^(log 8 to the base 2)
        h(n) = nlog(n) / n^3

        h(n) = (n^(-2)) * log(n)

        as we see -2 < 0
        
        U(n) = 1

        therefore T(n) = n^3 * 1

        T(n) = n^3

## Quicksort & Mergesort difference

QuickSort and Merge Sort are two popular sorting algorithms. Here are some differences between the two:

        1. QuickSort uses a pivot element to sort, while Merge Sort does not use the pivot element to sort an array.
        2. QuickSort is an internal sorting method where the data is sorted in main memory, while Merge Sort is an external sorting method in which the data that is to be sorted cannot be accommodated in the memory and needs auxiliary memory for sorting.
        3. Merge Sort is stable as two elements with equal value appear in the same order in the sorted output as they were in the input, while QuickSort is unstable.
        4. QuickSort is mostly preferred for large unsorted arrays, while Merge Sort is mostly applicable for linked lists.
        5. QuickSort is more efficient and works faster in smaller size arrays, as compared to Merge Sort. Merge Sort is more efficient and works faster in larger data sets or arrays, as compared to Quick Sort
