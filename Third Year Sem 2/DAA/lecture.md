# DAA Lecture Notes

## Lecture 8

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
