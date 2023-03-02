#include<bits/stdc++.h>
using namespace std;

// Author: Siddharth Sutar
// Date: 25 January 2023

// function 

class KnapSnackDP{
    public: 
    static int max(int a, int b) 
    { 
        return (a > b)? a : b; 
    }

    static int knapSack(int W, int wt[], int val[], int n) {
        int i, w;
        vector<vector<int>> K(n+1,vector<int>(W+1));
        for(i = 0; i <=n; i++) {
            for(w = 0; w<=W; w++) {
                if(i == 0 || w == 0){
                    K[i][w] = 0;
                }
                else if(wt[i-1] <= w){
                    K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
                }
                else{
                    K[i][w] = K[i-1][w];
                }
            }
        }

        // printing the matrix

        cout << endl;
        cout << "The Tabluar Matrix form" << endl;

        for(int j = 0; j <= n; j++){
            for(int l = 0; l <= W; l++){
                cout << K[j][l] << " ";
            }
            cout << endl;
        }
        cout << endl;

        vector<int> selected(n);
        int temp = K[n][W];

        // Previous algorithm
        // for(int i = n; i >= 0; i--){
        //     if(temp <= 0){
        //         break;
        //     }

        //     if(isPresent(K,i,W,temp)){
        //         continue;
        //     }
        //     else{
        //         if(val[i] > temp){
        //             continue;
        //         }
        //         else{
        //             temp = temp - val[i];
        //             selected[i] = 1;
        //         }
        //     }
        // }

        i = n;
        int j = W;
        while(i > 0 || j > 0){
            if(K[i][j] == K[i - 1][j]){
                selected[i - 1] = 0;
                i--;
            }
            else{
                selected[i - 1] = 1;
                i--;
                j = j - wt[i];
            }
        }

        cout << "Selected matrix" << endl;

        for(int i: selected){
            cout << i << " ";
        }

        cout << endl;

        cout << endl;
        cout << "The max value is: "; 
        return K[n][W];
    }

    static bool isPresent(vector<vector<int>> arr,int row,int col,int element){
        for(int i = 0; i <= col; i++){
            if(arr[row - 1][i] == element){
                return true;
            }
        }
        return false;        
    }

    int findSum(vector<int> weights, int n){
    // Sum all array elements
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += weights[i];

        // Result is sum * 2^(n-1)
        return sum * (1 << (n - 1));
    }
};

int main(int argc, char **argv){
    //type your code below
    int n,W;
    cout << "Enter number of elements" << endl;
    cin >> n;
    
    int wt[n],val[n];
    cout << "Enter the weights" << endl;
    for(int i = 0; i < n; i++){
        cin>>wt[i];
    }

    cout << "Enter the profit values" << endl;
    for(int i = 0; i < n; i++){
        cin>>val[i];
    }

    cout << "Enter the max capacity" << endl;
    cin >> W;

    KnapSnackDP ks;

    cout << ks.knapSack(W,wt,val,n) << endl;
    cout << "Time Complexity: n^2" << endl;
    cout << "Space Complexity: n^2" << endl;

    return 0;
}