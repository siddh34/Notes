// #include <mutex>
// #include <thread>
// #include <iostream>
// using namespace std;

// const int MAX = 4; // size of the matrices
// const int MAX_THREAD = 4; // number of threads

// int matA[MAX][MAX]; // first matrix
// int matB[MAX][MAX]; // second matrix
// int matC[MAX][MAX]; // result matrix
// mutex mtx[MAX][MAX]; // mutex array for synchronization

// // function to multiply a row by a column and store the result in matC
// void MatrixMultiplication(int row, int col) {
//     for (int i = 0; i < MAX; i++) {
//         mtx[row][col].lock(); // lock the element in matC
//         matC[row][col] += matA[row][i] * matB[i][col]; // multiply and add
//         mtx[row][col].unlock(); // unlock the element in matC
//     }
// }

// int main() {
//     // initialize matA and matB with some values
//     int count = 1;
//     for (int i = 0; i < MAX; i++) {
//         for (int j = 0; j < MAX; j++) {
//             matA[i][j] = count;
//             matB[i][j] = count;
//             count++;
//         }
//     }

//     // print matA and matB
//     std::cout << "Matrix A\n";
//     for (int i = 0; i < MAX; i++) {
//         for (int j = 0; j < MAX; j++) {
//             std::cout << matA[i][j] << " ";
//         }
//         std::cout << "\n";
//     }

//     std::cout << "Matrix B\n";
//     for (int i = 0; i < MAX; i++) {
//         for (int j = 0; j < MAX; j++) {
//             std::cout << matB[i][j] << " ";
//         }
//         std::cout << "\n";
//     }

//     // create an array of threads
//     thread threads[MAX_THREAD];

//     // loop through each element in matC
//     for (int row = 0; row < MAX; row++) {
//         for (int col = 0; col < MAX; col++) {
//             // create a thread to compute the element at (row, col)
//             threads[row * MAX + col] = std::thread(MatrixMultiplication, row, col);
//         }
//     }

//     // join all the threads
//     for (int i = 0; i < MAX_THREAD; i++) {
//         threads[i].join();
//     }

//     // print matC
//     std::cout << "Matrix C\n";
//     for (int i = 0; i < MAX; i++) {
//         for (int j = 0; j < MAX; j++) {
//             std::cout << matC[i][j] << " ";
//         }
//         std::cout << "\n";
//     }

//     return 0;
// }