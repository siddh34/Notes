#include<bits/stdc++.h>
using namespace std;

# define MAX 999999

// functions

void printMatrix(vector<vector<int>> matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

vector<int> minOfRow(vector<vector<int>> matrix){
    vector<int> minValues;
    for(int i = 0; i < matrix.size();i++){
        int max = MAX;  
        for(int j = 0; j < matrix[i].size();j++){
            max = min(max,matrix[i][j]);
        }
        minValues.push_back(max);
    }
    return minValues;
}

vector<int> minOfCol(vector<vector<int>> matrix){
    vector<int> minValues;
    for(int i = 0; i < matrix.size();i++){
        int max = MAX;  
        for(int j = 0; j < matrix[i].size();j++){
            max = min(max,matrix[j][i]);
        }
        minValues.push_back(max);
    }
    return minValues;
}

int main(int argc, char **argv){
    //type your code below
    vector<vector<int>> matrix = {{MAX,20,30,10,11},{15,MAX,16,4,2},{3,4,MAX,2,4},{19,6,18,MAX,3},{16,4,7,16,MAX}};

    cout << "Printing matrix..." << endl;
    printMatrix(matrix);

    cout << endl;

    vector<int> minValues = minOfRow(matrix); // getting minimum row elements

    for(int i = 0; i < minValues.size();i++){
        cout << minValues[i] << " ";
    }
    cout << endl;

    // subtracting min row elements
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            matrix[i][j] = matrix[i][j] - minValues[i];
        }
    }

    cout << "Printing matrix..." << endl;
    printMatrix(matrix);

    cout << endl;

    minValues = minOfCol(matrix); // getting minimum row elements

    for(int i = 0; i < minValues.size();i++){
        cout << minValues[i] << " ";
    }
    cout << endl;

    // subtracting min col elements
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            matrix[j][i] = matrix[j][i] - minValues[i];
        }
    }

    cout << "Printing Transformed matrix..." << endl;
    printMatrix(matrix);

    cout << endl;

    return 0;
}