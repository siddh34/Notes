# DAA Lecture Notes

## Lecture 6

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
