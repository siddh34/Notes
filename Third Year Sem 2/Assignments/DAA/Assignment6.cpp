#include<bits/stdc++.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
using namespace std;

// functions & variables for dining philosphers problem
#define N 5
sem_t chopsticks[5];
void* philos(void *);
void eat(int);

int main(int argc, char **argv){
    int i,n[5];
    pthread_t T[5];
    for(i = 0; i < 5; i++){
        sem_init(&chopsticks[i],0,1);
    }
    for(i = 0;i < 5; i++){
        n[i] = i;
        pthread_create(&T[i],NULL,philos,(void *)&n[i]);
    }

    for(i = 0;i < 5; i++){
        pthread_join(T[i],NULL);
    }
}

void *philos(void *n){
    int ph = *(int *)n;
    cout << "\nPhilosopher " << ph << " wants to eat" << endl;
    cout << "\nPhilosopher " << ph << " tries to pick left chopstick" << endl;
    sem_wait(&chopsticks[ph]);
    cout << "\nPhilosopher " << ph << " picks left chopstick" << endl;
    cout << "\nPhilosopher " << ph << " tries to pick right chopstick" << endl;
    sem_wait(&chopsticks[(ph + 1)%5]);
    cout << "\nPhilosopher " << ph << " picks right chopstick" << endl;
    eat(ph);
    Sleep(2);
    cout << "\nPhilosopher " << ph << " has done eating" << endl;
    sem_post(&chopsticks[(ph + 1)%5]);
    cout << "\nPhilosopher " << ph << " leaves the right chopsticks" << endl;
    sem_post(&chopsticks[ph]);
    cout << "\nPhilosopher " << ph << " leaves left chopsticks" << endl;
}

void eat(int ph){
    cout << "Philosopher " << ph << " is eating" << endl;
}