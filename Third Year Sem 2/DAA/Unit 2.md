# Unit 2

## Greedy method

1. An Optimization problem is one in which the aim is to either maximize or minimize a given objective function w. r. t. some constraints or conditions, given a set of input values

2. Greedy algorithm always makes the choice (greedy criteria) that looks best at the moment, to optimize a given objective function.

3. It makes a locally optimal choice

4. The greedy algorithm does not always guarantee the optimal solution but it generally produces solutions that are very close in value to the optimal

## Dynamic Programming

1. Dynamic Programming is an algorithmic paradigm that solves a given complex problem by breaking it into subproblems and stores the results of subproblems to avoid computing the same results again

2. There are two main properties of a problem

    a. Overlapping Sub problems

            In dynamic programming, computed solutions to subproblems are stored in a table so that these don’t have to be recomputed. So Dynamic Programming is not useful when there are no common (overlapping) subproblems because there is no point storing the solutions if they are not needed again

    b. Optimal Substructure

            A given problems has Optimal Substructure Property if optimal solution of the given problem can be obtained by using optimal solutions of its subproblems

            a. Memoization (Top Down)
                i. The memoized program for a problem is similar to the recursive version with a small modification that it looks into a lookup table before computing solutions
                ii. Whenever we need the solution to a subproblem, we first look into the lookup table. If the precomputed value is there then we return that value, otherwise, we calculate the value and put the result in the lookup table so that it can be reused later

            b. Tabulation (Bottom Up)
                i. The tabulated program for a given problem builds a table in bottom up fashion and returns the last entry from table

## KnapSack problem

The knapsack problem is the following problem in combinatorial optimization:

    Given a set of items, each with a weight and a value, determine which items to include in the collection so that the total weight is less than or equal to a given limit and the total value is as large as possible

Lets see it in a boarder view

    Suppose
    n (no of objects) = 
    m (max weight) = 15

| Object | O | 1 | 2  | 3 | 4 | 5 | 6 | 7 |
| -| -| -| -| -| -| -| -| - |
| Profit | P | 10 | 5 | 15 | 7 | 6 | 18 | 3 |
Weight | W | 2 | 3 | 5 | 7 | 1 | 4 | 1
P/W | R | 5 | 1.66 | 3 | 1 | 6 | 4.5 | 3 |

Let's see what object we can put

| Remaining weight | 15 | 14 | 12 | 8 | 3 | 2 | 0 |  
| - | - | - | - | - | - | - | - |
| Weight added |  1 | 2 | 4 | 5 |  1 | 2 | 0 |

Selected elements

| x1 | x2 | x3 | x4 | x5 |  x6 | x7 |
| - | - | - | - | - | - | - |
| 1 | 2/3|  1 | 0 | 1 | 1 | 1 |

SUM(xiwi) = 1 x 2 + 2/3 x 3 + 1 x 5 + 1 x 1 + 1 x 4 + 1 x 1  = 15

SUM(xipi) = 1 x 10 + 2/3 x 5 + 1 x 6 + 1 x 18 + 1 x 3 = 55.3

Q. Let's see the same problem but with steps again

    n = 7
    m = 5

| Object | O | 1 | 2  | 3 | 4 | 5 | 6 | 7 |
| -| -| -| -| -| -| -| -| - |
| Profit | P | 10 | 5 | 15 | 7 | 6 | 18 | 3 |
Weight | W | 2 | 3 | 5 | 7 | 1 | 4 | 1
P/W | R | 5 | 1.66 | 3 | 1 | 6 | 4.5 | 3 |

Just plot the table like below to get answer quickly

Selection with max profit

| Obj | profit | weight | remaining weight |
| - | - | - | - |
| 0 | 0 | 0 | 15 |
| 6 | 18 | 4 | 15 - 4 = 11 |
| 3 | 15 | 5 | 11 - 5 = 6 |
| 1 | 10 | 2 | 6 - 2 = 4 |
| Assumed | 4 * 1 = 4 | 4 | 4 - 4 = 0 |

max profit = 47

Selection with min weight

| Obj | profit | weight | remaining weight |
| - | - | - | - |
| 0 | 0 | 0 | 15 |
| 5 | 6 | 1 | 15 - 1 = 14 |
| 7 | 3 | 1 | 14 - 1 = 13 |
| 1 | 10 | 2 | 13 - 2 = 11 |
| 2 | 5 | 3 | 11 - 3 = 8 |
| 6 | 18 | 4 | 8 - 4 = 4 |
|  | 4 * 3 = 12 | 4 | 4 - 4 = 0 |

max profit = 54

Select  object with maximum pi/wi

| Obj | profit | weight | remaining weight |
| - | - | - | - |
| 0 | 0 | 0 | 15 |
| 5 | 6 | 1 | 15 - 1 = 14 |
| 1 | 10 | 2 | 14 - 2 = 12 |
| 6 | 18 | 4 | 12 - 4 = 8 |
| 3 | 15 | 5 | 8 - 5 = 3 |
| 7 | 3 | 1 | 3 - 1 = 2 |
| 2 | 2 * 1.66 | 2 | 2 - 2 = 0 |  

max profit = 55.34

Because of max pi/wi we will get **maximum value**

## Job Sequencing with deadlines

For the following sequence of a job find out final sequence and max profit

| Job | 1 |  2 | 3 | 4 | 5 | 6 | 7
| - | - | - | - | - | - | - | - |
| Profit | 3 | 5 | 20 | 18 | 0 | 6 | 30 |
| Deadline| 1 | 3 | 4 | 3 | 2 | 1 | 2 |

Solution

Step 1

| Job | 7 |  3 | 4 | 6 | 2 | 1 | 5
| - | - | - | - | - | - | - | - |
| Profit | 30 | 20 | 18 | 6 | 5 | 3 | 0 |
| Deadline| 2 | 4 | 3 | 1 | 3 | 1 | 2 |

Step 2

| 0 | 1 | 2 | 3 | 4 |
| - | - | - | - | - |

as deadline values are from 0 to 4

Step 3

| JOB | 7 | | | | | |
| - | - | - | - | - | - | - |
| Profit | 30 |
| Deadline | 2 |

Step 4

| JOB | 7 | 3 | 4 | 6 | | |
| - | - | - | - | - | - | - |
| Profit | 30 | 20 | 18 | 6 |
| Deadline | 2 | 4 | 3 | 1 |

Step 5

| Job | 6 | 7 | 4 | 3 |
| - | - | - | - | - |
| Profit | 6 | 30 | 18 | 20 |
| Deadline | 1 | 2 | 3 | 4 |  

Max profit is 74

Example 2

![Img](./Images/Job%20Scheduling.png)

## 0/1 KnapSack  using DP

    k(i,c) = max[(Pi + k(i - 1, c - wi),k(i - 1, c))]

    k(i,c) = 0 [i == 0 || c == 0]

    k(i,c) = k(i,c) [wi > c]

Some *Example*

| | 01 | 02 | 03 |
| - | - | - | - |
| P | 10 | 12 | 28 |
| W | 1 | 2 | 4 |

0 to 6 is capacity below and 0 to 3 are objects

| O/C | 00 | 01 | 02 | 03 | 04 | 05 | 06 |
| - | - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 |
| 2 | 0 |
| 3 | 0 |

    k(1,1) = max[(10 + k(1,1)),k(1,0)]
    k(1,1) = max[10,0]
    k(1,1) = 10

    k(1,2) = max[(10 + k(1,2)),k(1,2-1)]
    k(1,2) = max[10,0]
    k(1,2) = 10

| O/C | 00 | 01 | 02 | 03 | 04 | 05 | 06 |
| - | - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 10 |
| 2 | 0 |
| 3 | 0 |

    k(1,3) = max[(10 + k(0,2)),k(0,3)]
    k(1,3) = max[10,0]
    k(1,3) = 10

| O/C | 00 | 01 | 02 | 03 | 04 | 05 | 06 |
| - | - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 10 | 10 | 10 |
| 2 | 0 |
| 3 | 0 |

    k(1,3) = max[(10 + k(0,2)),k(0,3)]
    k(1,3) = max[10,0]
    k(1,3) = 10

    K(1,4) = K(1,5) = k(1,6) = max(10,0) = 10

| O/C | 00 | 01 | 02 | 03 | 04 | 05 | 06 |
| - | - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 10 | 10 | 10 | 10 | 10 | 10 |
| 2 | 0 |
| 3 | 0 |

    K(2,1) = K(2-1,1) = 10

| O/C | 00 | 01 | 02 | 03 | 04 | 05 | 06 |
| - | - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 10 | 10 | 10 | 10 | 10 | 10 |
| 2 | 0 | 10 |
| 3 | 0 |

    K(2,2) = MAX[12 + K(1,0),K(1,2)]
    K(2,2) = MAX[12,10]
    K(2,2) = 12

| O/C | 00 | 01 | 02 | 03 | 04 | 05 | 06 |
| - | - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 10 | 10 | 10 | 10 | 10 | 10 |
| 2 | 0 | 10 | 12 |
| 3 | 0 |

    K(2,3) = MAX(12+K(1,1),K(1,3))
    K(2,3) = MAX(12+10,10)
    K(2,3) = 22

| O/C | 00 | 01 | 02 | 03 | 04 | 05 | 06 |
| - | - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 10 | 10 | 10 | 10 | 10 | 10 |
| 2 | 0 | 10 | 12 | 22 |
| 3 | 0 |

    K(2,4) = MAX(12+K(1,2),K(1,4))
    K(2,4) = MAX(12+10,10)
    K(2,4) = 22

| O/C | 00 | 01 | 02 | 03 | 04 | 05 | 06 |
| - | - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 10 | 10 | 10 | 10 | 10 | 10 |
| 2 | 0 | 10 | 12 | 22 | 22 |
| 3 | 0 |

    K(2,5) = MAX(12+K(1,3),K(1,5))
    K(2,5) = MAX(12+10,10)
    K(2,5) = 22
    K(2,6) = 22

| O/C | 00 | 01 | 02 | 03 | 04 | 05 | 06 |
| - | - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 10 | 10 | 10 | 10 | 10 | 10 |
| 2 | 0 | 10 | 12 | 22 | 22 | 22 | 22 |
| 3 | 0 |

    K(3,1) = MAX(10,0)
    K(3,1) = 10

| O/C | 00 | 01 | 02 | 03 | 04 | 05 | 06 |
| - | - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 10 | 10 | 10 | 10 | 10 | 10 |
| 2 | 0 | 10 | 12 | 22 | 22 | 22 | 22 |
| 3 | 0 | 10 |

    K(3,2) = 12

| O/C | 00 | 01 | 02 | 03 | 04 | 05 | 06 |
| - | - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 10 | 10 | 10 | 10 | 10 | 10 |
| 2 | 0 | 10 | 12 | 22 | 22 | 22 | 22 |
| 3 | 0 | 10 | 12 |

    K(3,3) = 22

| O/C | 00 | 01 | 02 | 03 | 04 | 05 | 06 |
| - | - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 10 | 10 | 10 | 10 | 10 | 10 |
| 2 | 0 | 10 | 12 | 22 | 22 | 22 | 22 |
| 3 | 0 | 10 | 12 | 22 |

    K(3,4) = MAX(28 + K(2,0),K(2,4))
    K(3,4) = MAX(38,22)
    K(3,4) = 28

| O/C | 00 | 01 | 02 | 03 | 04 | 05 | 06 |
| - | - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 10 | 10 | 10 | 10 | 10 | 10 |
| 2 | 0 | 10 | 12 | 22 | 22 | 22 | 22 |
| 3 | 0 | 10 | 12 | 22 | 28 |

    K(3,5) = MAX(28 + K(2,1),K(2,5))
    K(3,4) = MAX(28 + 10 , 22)
    K(3,4) = 38

| O/C | 00 | 01 | 02 | 03 | 04 | 05 | 06 |
| - | - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 10 | 10 | 10 | 10 | 10 | 10 |
| 2 | 0 | 10 | 12 | 22 | 22 | 22 | 22 |
| 3 | 0 | 10 | 12 | 22 | 28 | 38 |

    K(3,6) = MAX(28 + K(2,2),K(2,6))
    K(3,6) = MAX(28 + 12, 22)
    K(3,6) = 40

| O/C | 00 | 01 | 02 | 03 | 04 | 05 | 06 |
| - | - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 10 | 10 | 10 | 10 | 10 | 10 |
| 2 | 0 | 10 | 12 | 22 | 22 | 22 | 22 |
| 3 | 0 | 10 | 12 | 22 | 28 | 38 | 40 |

EXAMPLE *2*

NO OF ITEMS = 4

MAX WEIGHT = 5

WEIGHTS --> 2, 1, 3, 2

VALUES --> 12, 10, 20, 15

| C/O | 00 | 01 | 02 | 03 | 04 | 05 |
| - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 |
| 2 | 0 |
| 3 | 0 |
| 4 | 0 |

    K(1,1) = 0

| C/O | 00 | 01 | 02 | 03 | 04 | 05 |
| - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 |
| 2 | 0 |
| 3 | 0 |
| 4 | 0 |

    K(1,2) = MAX[12 + K(0,0),K(0,2)]
    K(1,2) = MAX[12,0]
    K(1,2) = 12

| C/O | 00 | 01 | 02 | 03 | 04 | 05 |
| - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 12 |
| 2 | 0 |
| 3 | 0 |
| 4 | 0 |

    K(1,3) = MAX[12 + K(0,1),K(0,3)]
    K(1,2) = MAX[12,0]
    K(1,2) = 12

| C/O | 00 | 01 | 02 | 03 | 04 | 05 |
| - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 12 | 12 |
| 2 | 0 |
| 3 | 0 |
| 4 | 0 |

    K(1,4) = K(1,5) = 12

| C/O | 00 | 01 | 02 | 03 | 04 | 05 |
| - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 12 | 12 | 12 | 12 |
| 2 | 0 |
| 3 | 0 |
| 4 | 0 |

    K(2,1) = MAX[10 + K(1,0),K(1,1)]
    K(2,1) = MAX[10,0]
    K(2,1) = 10

| C/O | 00 | 01 | 02 | 03 | 04 | 05 |
| - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 12 | 12 | 12 | 12 |
| 2 | 0 | 10 |
| 3 | 0 |
| 4 | 0 |

    K(2,2) = MAX[10 + K(1,1),K(1,2)]
    K(2,2) = MAX[10,12]
    K(2,2) = 12

| C/O | 00 | 01 | 02 | 03 | 04 | 05 |
| - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 12 | 12 | 12 | 12 |
| 2 | 0 | 10 | 12 |
| 3 | 0 |
| 4 | 0 |

    K(2,3) = MAX[10 + K(1,2),K(1,3)]
    K(2,3) = MAX[10 + 12 ,12]
    K(2,3) = 22

| C/O | 00 | 01 | 02 | 03 | 04 | 05 |
| - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 12 | 12 | 12 | 12 |
| 2 | 0 | 10 | 12 | 22 |
| 3 | 0 |
| 4 | 0 |

    K(2,4) = MAX[10 + K(1,3),K(1,4)]
    K(2,4) = MAX[10 + 12 ,12]
    K(2,4) = 22

    K(2,4) = K(2,5)

| C/O | 00 | 01 | 02 | 03 | 04 | 05 |
| - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 12 | 12 | 12 | 12 |
| 2 | 0 | 10 | 12 | 22 | 22 | 22 |
| 3 | 0 |
| 4 | 0 |

    K(3,1) = K(2,1)
    K(3,1) = 10

| C/O | 00 | 01 | 02 | 03 | 04 | 05 |
| - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 12 | 12 | 12 | 12 |
| 2 | 0 | 10 | 12 | 22 | 22 | 22 |
| 3 | 0 | 10 |
| 4 | 0 |

    K(3,2) = K(2,2)
    K(3,2) = 12

| C/O | 00 | 01 | 02 | 03 | 04 | 05 |
| - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 12 | 12 | 12 | 12 |
| 2 | 0 | 10 | 12 | 22 | 22 | 22 |
| 3 | 0 | 10 | 12 |
| 4 | 0 |

    K(3,3) = MAX[20 + K(2,0),K(2,3)]
    K(3,2) = MAX[20 + 0,22]
    K(3,2) = 22

| C/O | 00 | 01 | 02 | 03 | 04 | 05 |
| - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 12 | 12 | 12 | 12 |
| 2 | 0 | 10 | 12 | 22 | 22 | 22 |
| 3 | 0 | 10 | 12 | 22 |
| 4 | 0 |

    K(3,4) = MAX[20 + K(2,1),K(2,4)]
    K(3,4) = MAX[20 + 10,22]
    K(3,4) = 30

| C/O | 00 | 01 | 02 | 03 | 04 | 05 |
| - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 12 | 12 | 12 | 12 |
| 2 | 0 | 10 | 12 | 22 | 22 | 22 |
| 3 | 0 | 10 | 12 | 22 | 30 |
| 4 | 0 |

    K(3,5) = MAX[20 + K(2,2),K(2,5)]
    K(3,5) = MAX[20 + 12,22]
    K(3,5) = 32

| C/O | 00 | 01 | 02 | 03 | 04 | 05 |
| - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 12 | 12 | 12 | 12 |
| 2 | 0 | 10 | 12 | 22 | 22 | 22 |
| 3 | 0 | 10 | 12 | 22 | 30 | 32 |
| 4 | 0 |

    K(4,1) = K(3,1)
    K(4,1) = 10

| C/O | 00 | 01 | 02 | 03 | 04 | 05 |
| - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 12 | 12 | 12 | 12 |
| 2 | 0 | 10 | 12 | 22 | 22 | 22 |
| 3 | 0 | 10 | 12 | 22 | 30 | 32 |
| 4 | 0 | 10 |

    K(4,2) = MAX[15 + K(3,0),K(3,2)]
    K(4,2) = MAX[15,12]
    K(4,2) = 15

| C/O | 00 | 01 | 02 | 03 | 04 | 05 |
| - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 12 | 12 | 12 | 12 |
| 2 | 0 | 10 | 12 | 22 | 22 | 22 |
| 3 | 0 | 10 | 12 | 22 | 30 | 32 |
| 4 | 0 | 10 | 15 |

    K(4,3) = MAX[15 + K(3,1),K(3,3)]
    K(4,3) = MAX[15 + 10,22]
    K(4,3) = 25

| C/O | 00 | 01 | 02 | 03 | 04 | 05 |
| - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 12 | 12 | 12 | 12 |
| 2 | 0 | 10 | 12 | 22 | 22 | 22 |
| 3 | 0 | 10 | 12 | 22 | 30 | 32 |
| 4 | 0 | 10 | 15 | 25 |

    K(4,4) = MAX[15 + K(3,2),K(3,4)]
    K(4,4) = MAX[15 + 12,30]
    K(4,4) = 30

| C/O | 00 | 01 | 02 | 03 | 04 | 05 |
| - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 12 | 12 | 12 | 12 |
| 2 | 0 | 10 | 12 | 22 | 22 | 22 |
| 3 | 0 | 10 | 12 | 22 | 30 | 32 |
| 4 | 0 | 10 | 15 | 25 | 30 |

    K(4,5) = MAX[15 + K(3,3),K(3,5)]
    K(4,5) = MAX[15 + 22,32]
    K(4,5) = 37

| C/O | 00 | 01 | 02 | 03 | 04 | 05 |
| - | - | - | - | - | - | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 12 | 12 | 12 | 12 |
| 2 | 0 | 10 | 12 | 22 | 22 | 22 |
| 3 | 0 | 10 | 12 | 22 | 30 | 32 |
| 4 | 0 | 10 | 15 | 25 | 30 | 37 |

### Analysis of Knapsnack Algo

1. To sort the objects in non-increasing order of pi/wi,computation time = O(nlogn)
2. While loop will be executed ‘n’ times in worst case, so the
computation time = O(n)
3. Time complexity = O(nlogn)
4. Space complexity = c + space required for x[1:n] = O(n)

## OBST ( An Optimal Binary Search Tree )

* An Optimal Binary Search Tree (OBST), also known as a Weighted Binary Search Tree, is a binary search tree that minimizes the expected search cost

* In a binary search tree, the search cost is the number of comparisons required to search for a given key

* In an OBST, each node is assigned a weight that represents the probability of the key being searched for being present in the subtree rooted at that node. The tree is constructed such that the expected search cost is minimized

* The optimal binary search tree is generally divided into two types:

        1. Static 
            a. In the static optimality problem, the tree cannot be modified after it has been constructed
            b. In this case, there exists some particular layout of the tree that minimizes the expected search cost
        2. Dynamic
            a. In the dynamic optimality problem, the tree can be modified after it has been constructed
            b. In this case, the tree is constructed incrementally, and the goal is to minimize the expected search cost at each step

IMP *Note*: Cost contribution of internal node ai is p(i) * level(ai)

> How to construct OBST?

    •To apply DP approach for obtaining OBST, we need to view the
    construction of such a tree as the result of sequence of decisions
    and observe that the principle of optimality holds.
    •A possible approach to this would be to decide which of the ai’s
    (with weights pi’s) should be selected as the root node of the tree.
    •If we choose ak as the root node from a1, a2, …, an (sorted in non decreasing order) , then it is clear that the internal nodes a1, a2, …,
    ak-1 and external nodes for classes E0, E1, E2, …, Ek-1 will be in
    the left sub tree l and the internal nodes ak+1, ak+2, …, an and
    external nodes for classes Ek+1, Ek+2, …, En will be in the right
    sub tree r. Let root ak be at level 1

Note:

    Probability of unsuccessful searches = Σ q[i]

    Probability of successful searches = Σ p[i]

    Σ p[i] + Σ q[i] = 1

## Huffman Coding

    Suppose certain string cost 180 bits to send but with the help of huffman coding we can encode it to less than 180 bits

    Consider the following text:
    ABBCDBCCDAABBEEEBEAB – 20 characters
    Now we know that the characters (A B C D E) are repeated in the message. 
    
    If there are 4 characters we can represent them with fixed 2 bits as 2 2 = 4 codes.
    But we have 5 different characters , thus we will require 3 bit code to represent 
    them as 2 3 = 8.

    Thus we can have code as below:
    A - 000 B – 001 C – 010 D – 011 E – 100 
    So now how many bits will be required 20 * 3 = 60 bits

    But now along with this 60 bits of encoding the sender will also have to send 
    characters and their codes for receiver to decode the message.

    Therefore 8 bits ASCII code for 5 characters = 40
    + Total No. of bits required for encoding ( 5 * 3) =15 

    Total = 40 + 15 = 55 bits
    
    Hence the total number of bits that will be sent is 60 + 55 = 115 bits

## Multistage graphs

* Its like dijikstra's algorithm

* Finding a minimum cost path from suppose ‘s’ to ‘t’

 Solution by DP

    Forward Approach :
    •cost (i, j) = min{c(j, l) + cost(i+1, l)}
    l Є Vi+1 and < j, l > Є E

    Backward Approach :
    •bcost (i, j) = min{c(l, j) + bcost(i-1, l)}
    l Є Vi-1 and < l, j > Є E

    Example : Find shortest path from s to t for the above multi-stage graph 
    using forward and backward approach.
    Analysis (Fgraph and Bgraph):
 
    Time Complexity = θ(|V| + |E|)
    Space Complexity = θ(n+k) … k is number of stages.
