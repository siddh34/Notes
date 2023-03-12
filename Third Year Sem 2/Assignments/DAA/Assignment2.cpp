#include <bits/stdc++.h>
using namespace std;

// Author: Siddharth Sutar
// Date: 25 January 2023

// function

class KnapSnackDP
{
public:
    static int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    static int knapSack(int W, int wt[], int val[], int n, int wantRec)
    {
        int isRecurssive = wantRec;
        int i, w;
        vector<vector<int>> K(n + 1, vector<int>(W + 1));
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();

        int res = 0;

        if (isRecurssive == 0)
        {
            for (i = 0; i <= n; i++)
            {
                for (w = 0; w <= W; w++)
                {
                    if (i == 0 || w == 0)
                    {
                        K[i][w] = 0;
                    }
                    else if (wt[i - 1] <= w)
                    {
                        K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
                    }
                    else
                    {
                        K[i][w] = K[i - 1][w];
                    }
                }
            }

            res = K[n][W];
        }
        else
        {
            res = knapSack2(W,wt,val,n,K);
            end = std::chrono::system_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - start;
            std::time_t end_time = std::chrono::system_clock::to_time_t(end);

            std::cout << "finished computation at " << std::ctime(&end_time)
                        << "elapsed time: " << elapsed_seconds.count() << "s\n";

            cout << "Max value via Recurssion: " << endl;

            return res;
        }

        end = std::chrono::system_clock::now();

        std::chrono::duration<double> elapsed_seconds = end - start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);

        std::cout << "finished computation at " << std::ctime(&end_time)
                    << "elapsed time: " << elapsed_seconds.count() << "s\n";
        // printing the matrix

        cout << endl;
        cout << "The Tabluar Matrix form" << endl;

        for (int j = 0; j <= n; j++)
        {
            for (int l = 0; l <= W; l++)
            {
                cout << K[j][l] << " ";
            }
            cout << endl;
        }
        cout << endl;

        vector<int> selected(n);
        int temp = K[n][W];

        i = n;
        int j = W;
        while (i > 0 || j > 0)
        {
            if (K[i][j] == K[i - 1][j])
            {
                selected[i - 1] = 0;
                i--;
            }
            else
            {
                selected[i - 1] = 1;
                i--;
                j = j - wt[i];
            }
        }

        cout << "Selected matrix" << endl;

        for (int i : selected)
        {
            cout << i << " ";
        }

        cout << endl;

        cout << endl;
        cout << "The max value is: ";
        return res;
    }

    static int knapSack2(int W, int wt[], int val[], int n,vector<vector<int>> K)
    {

        // Base Case
        if (n == 0 || W == 0)
            return 0;

        if (wt[n - 1] > W)
            return knapSack2(W, wt, val, n - 1,K);

        else
            return max(
                val[n - 1] + knapSack2(W - wt[n - 1], wt, val, n - 1,K),
                knapSack2(W, wt, val, n - 1,K));
    }
};

int main(int argc, char **argv)
{
    // type your code below
    int n, W, wantRec;
    cout << "Enter number of elements" << endl;
    cin >> n;

    int wt[n], val[n];
    cout << "Enter the weights" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    cout << "Enter the profit values" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    cout << "Enter the max capacity" << endl;
    cin >> W;

    cout << "Do you want recurrsion to take place?\nEnter 0 if not else enter any key" << endl;
    cin >> wantRec;

    KnapSnackDP ks;

    cout << ks.knapSack(W, wt, val, n, wantRec) << endl;
    cout << "Time Complexity: n^2" << endl;
    cout << "Space Complexity: n^2" << endl;

    return 0;
}