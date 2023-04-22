# DAA Lecture 19

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
