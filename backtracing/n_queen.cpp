#include<bits/stdc++.h>
using namespace std;

bool isSafe(int** board, int x, int y,int boardSize){
    for(int i=0; i<y; i++)
        if(board[x][i] == 1)
            return false;
        
    for(int i=0;i<x; i++)
        if(board[i][y] == 1)
            return false;
            
    int p=x-1,q=y-1;
    while(p>=0 && q>=0)
        if(board[p--][q--]==1)
            return false;

    p=x-1,q=y+1;
    while(p>=0 && q < boardSize)
        if(board[p--][q++] == 1)
            return false;
    return true;
}


bool nQueen(int** board, int x, int n){
    if(x>=n)
        return true;

    for(int col = 0; col<n; col++){
        if(isSafe(board,x,col,n)){
            board[x][col] = 1;
            if(nQueen(board,x+1,n))
                return true;
            board[x][col] = 0;
        }
    }
    return false;
}


int main(){

    int n;
    cout<<"enter size of board : ";
    cin>>n;

    int** arr = new int*[n];

    for(int i=0; i<n; i++){
        arr[i] = new int[n];
        for(int j=0; j<n; j++)
            arr[i][j] = 0;
    }

    if(nQueen(arr,0,n)){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                cout<<arr[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}