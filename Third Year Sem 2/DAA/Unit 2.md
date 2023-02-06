# Unit 2

## KnapSack problem

The knapsack problem is the following problem in combinatorial optimization:

    Given a set of items, each with a weight and a value, determine which items to include in the collection so that the total weight is less than or equal to a given limit and the total value is as large as possible

Lets see it in a boarder view

    Suppose
    n (no of objects) = 7
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

Because of max pi/wi we will get maximum value

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
