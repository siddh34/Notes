# DAA Lecture Notes

## Lecture 4

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
