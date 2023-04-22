# Unit 6

## Amdahl's law

* It is formula used to find

* Max improvement possible by improving particular part of system

* Helcomputing it is used to predict

* Speed up of programme using multiple processes

* Preparing run in parallel computation it can br **serial**, **Parallel** or **Both**

| F | 1 - F |
| - | ----- |
| Serial | Parallel |

Computation of a programme

    <= 1 / (F + ((1-F)/P))

Single Processor Time ( SCM )

* It equals

         Single processor time /  n processors time

Note:

        Computational time = Serial Exec + parallel exec

| F | 1 - F |
| - | ----- |
| Serial | Parallel |

Parallel = 1 - F / n

S(n) <= 1 / (F + ((1 - F)/n))

## Theorem Based Problem

1. T(n) < n^(log of a to the base b)

    T(n) = Theta ( n ^ (log of a to the base b))

2. F(n) = n ^ (log of a to the base b)

    T(n) = Theta ( n ^ (log of a to the base b) log n)

3. F(n) > n ^ (log of a to the base b)

    T(n) = Theta * F(n)

Example

1. T(n) = 2T(n/2) + n^2

2. T(n) = T(9n/10) + n

3. T(n) = 8T(n/4) + n^2

## Dinning Philosopher

```Cpp

#define N5
#define Thinking 0
#define Hungry 1
#define eating 2
#define Left (i+N-1)%N
#define Right (i+1)%N

B Semaphore mutex=1;
B Semaphore S[N]={0};

int state[N]=0;
void Philosopher(int i)
{
    while(True){
        Thinking();
        Take Forks(1);
        Eat();
    }
    PutForks(1);
}
void TakeForks(int i){
    down mutex;
    state[i]=Hungry;
    Test(i);
    up mutex;
}down(S[i]);

void Test(int i){
    if(state(i)==Hungry && state[Left!=Eating] && state[Right!=Eating]){
        state[i]=Eating;
    }up(S[i]);
}

void PutForks(int i){
    down mutex;
    state[i]=Thinking;
    Test[Left];
    Test[Right];
    up mutex;
}

```
