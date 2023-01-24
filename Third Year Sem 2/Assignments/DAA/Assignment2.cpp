#include<bits/stdc++.h>
using namespace std;

// function 

class KnapSnackDP{
    public: 
    static int max(int a, int b) 
    { 
        return (a > b)? a : b; 
    }

    static int knapSack(int W, int wt[], int val[], int n) {
        int i, w;
        int K[n + 1][W + 1];
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

        // TODO: check whether element is available in previous row, print vector of 1/0
        vector<int> selected(n);
        int temp = K[n][W];
        // for(int i = 0; i <= n; i++){
        //     for(int j = 0; j <= W; j++){
        //         if(){

        //         }
        //     }
        // }


        cout << endl;
        cout << "The max value is: "; 
        return K[n][W];
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

    return 0;
}