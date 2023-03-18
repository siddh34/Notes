#include<bits/stdc++.h>
using namespace std;

# define MAX 999999
vector<int> costRec; // cost record

// functions

// prints vector
void printMatrix(vector<vector<int>> matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void printMatrix(vector<int> matrix){
    for(int i = 0; i < matrix.size(); i++){
            cout << matrix[i] << "\t";
        cout << endl;
    }
}

// finds min vector for row
vector<int> minOfRow(vector<vector<int>> matrix){
    vector<int> minValues;
    for(int i = 0; i < matrix.size();i++){
        int max = MAX;  
        for(int j = 0; j < matrix[i].size();j++){
            max = min(max,matrix[i][j]);
        }

        if(max == MAX){
            max = 0;
        }

        minValues.push_back(max);
    }
    return minValues;
}

// finds min vector for column
vector<int> minOfCol(vector<vector<int>> matrix){
    vector<int> minValues;
    for(int i = 0; i < matrix.size();i++){
        int max = MAX;  
        for(int j = 0; j < matrix[i].size();j++){
            max = min(max,matrix[j][i]);
        }

        if(max == MAX){
            max = 0;
        }

        minValues.push_back(max);
    }
    return minValues;
}

// column reduction
vector<vector<int>> colRed(vector<vector<int>> mat){
    vector<int> minValues = minOfCol(mat); // getting minimum col elements

    // subtracting min col elements
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[i].size(); j++){
            mat[j][i] = mat[j][i] - minValues[i];
        }
    }

    return mat;
}

// row reduction
vector<vector<int>> rowRed(vector<vector<int>> mat){
    vector<int> minValues = minOfRow(mat); // getting minimum row elements

    // subtracting min row elements
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[i].size(); j++){
            mat[i][j] = mat[i][j] - minValues[i];
        }
    }

    return mat;
}

// gives of sum of all elements in vector
int sum(vector<int> m){
    int sum = 0;

    for(int i = 0; i < m.size(); i++){
        sum += m[i];
    }

    return sum;
}

// gives reduced matrix & cost
vector<vector<int>> redMatrix(vector<vector<int>> mat){
    vector<int> minRow = minOfRow(mat); // minimum values of rows columns
    int sumRow = sum(minRow);
    mat = rowRed(mat);
    vector<int> minColumn = minOfCol(mat);  // minimum value of columns
    int sumCol = sum(minColumn);
    costRec.push_back(sumRow + sumCol);
    mat = colRed(mat);
    return mat;
}

// gives reduced matrix & cost
vector<vector<int>> redMatrix(vector<vector<int>> mat,int row,int col){

    // infinity work
    

    vector<int> minRow = minOfRow(mat); // minimum values of rows columns
    int sumRow = sum(minRow);
    mat = rowRed(mat);
    vector<int> minColumn = minOfCol(mat);  // minimum value of columns
    int sumCol = sum(minColumn);
    costRec.push_back(sumRow + sumCol);
    mat = colRed(mat);
    return mat;
}


vector<int> path(vector<vector<int>> mat){
    vector<int> result; // result path
    vector<int> rec; // record of visited points
    vector<vector<int>> temp = mat; // temporary vector matrix to save our matrix
    int n = mat.size(); // row iteration
    int m = n; // col iteration
    int sumCol = 0; // sum of column values
    int sumRow = 0; // sum of row values
    int reductionMainCost = 0;

    // first reduction
    mat = redMatrix(mat);
    reductionMainCost = costRec[0];
    costRec.clear();
    temp = mat;

    for(int i = 1; i <= n;i++){

    }


    return result;
}


#include<bits/stdc++.h> 
using namespace std; 
#define V 8

int N = 8; 
int final_path[V + 1]; 
bool visited[V]; 
int final_res = INT_MAX; 

void copyToFinal(int curr_path[]) 
{ 
    for (int i = 0; i < N; i++) 
        final_path[i] = curr_path[i]; 
    final_path[N] = curr_path[0]; 
} 

int firstMin(int adj[][V], int i) 
{ 
    int min = INT_MAX; 
    for (int k = 0; k < N; k++) 
        if (adj[i][k] < min && i != k) 
            min = adj[i][k]; 
    return min; 
} 

int secondMin(int adj[][V], int i) 
{ 
    int first = INT_MAX, second = INT_MAX; 
    for (int j=0; j<N; j++) 
    { 
        if (i == j) 
            continue; 
        if (adj[i][j] <= first) 
        { 
            second = first; 
            first = adj[i][j]; 
        } 
        else if (adj[i][j] <= second && 
                adj[i][j] != first) 
            second = adj[i][j]; 
    } 
    return second; 
} 

void TSPRec(int adj[][V], int curr_bound, int curr_weight, 
            int level, int curr_path[]) 
{ 
    if (level == N) 
    { 
        if (adj[curr_path[level - 1]][curr_path[0]] != 0) 
        { 
            int curr_res = curr_weight + 
                    adj[curr_path[level-1]][curr_path[0]]; 

            if (curr_res < final_res) 
            { 
                copyToFinal(curr_path); 
                final_res = curr_res; 
            } 
        } 
        return; 
    } 

    for (int i = 0; i < N; i++) 
    { 
        if (adj[curr_path[level-1]][i] != 0 && 
            visited[i] == false) 
        { 
            int temp = curr_bound; 
            curr_weight += adj[curr_path[level-1]][i]; 

            if (level==1) 
              curr_bound -= ((firstMin(adj, curr_path[level-1]) + 
                            firstMin(adj, i))/2); 
            else
              curr_bound -= ((secondMin(adj, curr_path[level-1]) + 
                            firstMin(adj, i))/2); 

            if (curr_bound + curr_weight < final_res) 
            { 
                curr_path[level] = i; 
                visited[i] = true; 

                TSPRec(adj, curr_bound, curr_weight, level+1, 
                        curr_path); 
            } 

            curr_weight -= adj[curr_path[level-1]][i]; 
            curr_bound = temp; 

            memset(visited, false, sizeof(visited)); 
            for (int j=0; j<=level-1; j++) 
                visited[curr_path[j]] = true; 
        } 
    } 
} 

void TSP(int adj[][V]) 
{ 
    int curr_path[N + 1]; 

    int curr_bound = 0; 
    memset(curr_path, -1, sizeof(curr_path)); 
    memset(visited, 0, sizeof(curr_path)); 

    for (int i = 0; i < N; i++) 
        curr_bound += (firstMin(adj, i) + secondMin(adj, i)); 

    curr_bound = (curr_bound&1)? curr_bound/2 + 1 : curr_bound/2; 

    visited[0] = true; 
    curr_path[0] = 0; 

    TSPRec(adj, curr_bound, 0, 1, curr_path); 
} 

int main(int argc, char **argv){
    //type your code below
    // vector<vector<int>> matrix = {{MAX,20,30,10,11},{15,MAX,16,4,2},{3,5,MAX,2,4},{19,6,18,MAX,3},{16,4,7,16,MAX}};

    // cout << "Initial matrix..." << endl;
    // printMatrix(matrix);

    // cout << endl;

    // vector<int> rec = path(matrix);

    // int adj[4][4] = { { 0, 10, 15, 20}, 
    //                     { 10, 0, 35, 25}, 
    //                     { 15, 35, 0, 30}, 
    //                     { 20, 25, 30, 0}}; 

    // int adj[5][5] = { { 0, 10, 15, 20, 11 }, 
    //                     { 10, 0, 35, 25, 12 }, 
    //                     { 15, 35, 0, 30, 50 }, 
    //                     { 20, 25, 30, 0, 12 }, 
    //                     { 20, 12, 11, 4, 0  } }; 

    // int adj[6][6] = {   { 0, 10, 15, 20, 11, 18}, 
    //                     { 10, 0, 35, 25, 12, 4 }, 
    //                     { 15, 35, 0, 30, 50, 7 }, 
    //                     { 20, 25, 30, 0, 12, 32}, 
    //                     { 20, 12, 11, 4, 0, 45 },
    //                     { 12, 34, 5, 64, 23, 0}}; 

    int adj[8][8] = {   { 0, 10, 15, 20, 11, 18,12 ,11}, 
                        { 10, 0, 35, 25, 12, 4, 12 ,11 }, 
                        { 15, 35, 0, 30, 50, 7, 12 ,11 }, 
                        { 20, 25, 30, 0, 12, 32,12 ,12 }, 
                        { 20, 12, 11, 4, 0, 45, 12 ,12 },
                        { 12, 34, 5, 64, 23, 0, 15 ,12 },
                        { 12, 34, 5, 64, 23, 12, 0 , 12},
                        { 12, 34, 5, 64, 23, 45, 13, 0 }
                        }; 

    // printing the matrix

    cout << "Starting matrix" << endl;
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            cout << adj[i][j] << "\t";
        }
        cout << endl;
    }

    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now(); 

    TSP(adj); 

    cout<<"Minimum cost : "<<final_res<<endl; 
    cout<<"Path Taken : "; 
    for (int i=0; i<=N; i++) 
        cout<<final_path[i]<<" "; 
    cout<<endl; 

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
                << "elapsed time: " << elapsed_seconds.count() << "s\n";    

    return 0;
}