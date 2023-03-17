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




int main(int argc, char **argv){
    //type your code below
    vector<vector<int>> matrix = {{MAX,20,30,10,11},{15,MAX,16,4,2},{3,5,MAX,2,4},{19,6,18,MAX,3},{16,4,7,16,MAX}};

    cout << "Initial matrix..." << endl;
    printMatrix(matrix);

    cout << endl;

    vector<int> rec = path(matrix);



    return 0;
}