#include <bits/stdc++.h>
#include <thread>
#include <unistd.h>
using namespace std;

int MAX = 4;
int MAX_THREAD = 4;
int matrixA[4][4];
int matrixB[4][4];
int matrixC[4][4];
int step_i = 0;

void *multiply(void *arg)
{
    int i = step_i++; // i denotes row number of resultant matC

    for (int j = 0; j < MAX; j++)
        for (int k = 0; k < MAX; k++)
            matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
}

void multiply(){
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                matrixC[i][j] = 0;
                for (int k = 0; k < MAX; k++)
                    matrixC[i][j] = matrixC[i][j] + matrixA[i][k] * matrixB[k][j];
            }
        }
}

int main(int argc, char **argv)
{
    // type your code below
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            cin >> matrixA[i][j];
        }
    }

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            cin >> matrixB[i][j];
        }
    }
    
    // Displaying matrixA & matrixB
    cout << "MATRIX A" << endl;
    for(int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            cout << matrixA[i][j] << " ";
        }        
        cout << endl;
    }
    
    cout << "MATRIX B" << endl;
    for(int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            cout << matrixB[i][j] << " ";
        }        
        cout << endl;
    }


    // pthread_t threads[MAX_THREAD];

    // for (int i = 0; i < MAX_THREAD; i++)
    // {
    //     int *p;
    //     pthread_create(&threads[i], NULL, multiply, (void *)(p));
    // }

    // // joining and waiting for all threads to complete
    // for (int i = 0; i < MAX; i++)
    // {
    //     pthread_join(threads[i], NULL);
    // }
    
    multiply();

    // Displaying the result matrix
    cout << endl
         << "Multiplication of A and B" << endl;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
            cout << matrixC[i][j] << " ";
        cout << endl;
    }
    
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    
    std::cout << "finished computation at " << std::ctime(&end_time)
                << "elapsed time: " << elapsed_seconds.count() << "s\n";

    return 0;
}