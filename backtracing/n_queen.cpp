#include<bits/stdc++.h>

using namespace std;

bool isSafe(vector<vector<int>> board, int boardSize, int x, int y){
    cout<<x<<" "<<y<<endl;
    for(int i=0; i< boardSize; i++){
        if(board[x][i] == 1 || board[i][y] == false){
            return false;
        }
    }
    for(int i =0; i<boardSize; i++){
        if(board[x+i][y-i] == 1 || x+i < boardSize || y-i > 0 ){
            return false;
        }
    }
    for(int i =0; i<boardSize; i++){
        if(board[x+i][y+i] == 1 || x+i <boardSize || y+i <boardSize){
            return false;
        }
    }
    return true;
}

bool placeNQueens(vector<vector<int>> &board, int x, int y, int boardSize){
    if(x== boardSize -1 || y == boardSize-1){
        return true;
    }

    for(int i=0; i<boardSize; i++){
        // cout<<x<<" "<<y<<endl;
        if(isSafe(board,boardSize, x, y)){
        board[x][y] = 1;      
        placeNQueens(board, x+1, y +1, boardSize);
            return true;
        board[x][y] = 0;             
    }
  }
  return false;
}

int main(){

    int n;
    cout<<"enter the number of quenes";
    cin>>n;
    vector<vector<int>> board(n,vector<int>(n));

    for(int i=0; i<n; i++){
        for(int j =0; j<n; j++){
            board[i][j] = 0;
        }
    }

    placeNQueens(board,0, 0, n);
    

    for(auto i : board){
        for(auto j : i){
            cout<<j<<" \t";
        }
        cout<<endl;
    }
}