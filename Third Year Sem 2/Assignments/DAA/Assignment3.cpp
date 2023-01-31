#include<bits/stdc++.h>
using namespace std;

# define n 4

class NQueens{
    public:
        void printSolution(vector<vector<int>> board){
            for(int i = 0; i < board.size();i++){
                for(int j = 0;j < board[i].size(); j++){
                    if(board[i][j]){
                        cout << "Q ";
                    }
                    else{
                        cout << ". ";
                    }
                }
                cout << endl;
            }
        }

        bool isSafe(vector<vector<int>> board,int row,int col){
            int i, j;

            // check on left side
            for(i = 0; i < col; i++){
                if(board[row][i]){
                    return false;
                }
            }

            // check on uppper diagonal side
            for(i = row, j = col; i >= 0 && j >= 0; i--, j--){
                if(board[i][j]){
                    return false;
                }
            }

            // check on lower diagonal side
            for(i = row, j = col; j >= 0 && i < n; i++, j--){
                if(board[i][j]){
                    return false;
                }
            }

            return true;
        }

        bool rSolve(vector<vector<int>> board, int col){
            if(col >= n){
                return true;
            }

            for(int i = 0; i < n; i++) {
                if(isSafe(board,i,col)){

                    board[i][col] = 1;

                    if(rSolve(board,col+1)){
                        return true;
                    }

                    board[i][col] = 0;
                }

            }

            return false;
        }

        bool solution(){
            vector<vector<int>> board(n,vector<int>(n,0));

            if (rSolve(board,0) == false){
                cout << "Solution doesn't exist" << endl;
                return false;
            } 

            printSolution(board);
            return true;
        }
};

int main(int argc, char **argv){
    //type your code below
    NQueens nq;
    nq.solution();
    return 0;
}