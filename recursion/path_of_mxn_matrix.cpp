#include<bits/stdc++.h>
using namespace std;


void getPath(vector<vector<int>> mat, int row, int col, int m, int n, vector<vector<int>> ans, vector<int> curr_path){
 
    if(row> m || col >n){
        return;
    }

    if(row == m-1 && col == n-1){
        cout<<"here";
        ans.push_back(curr_path);
        return;
    }

    if(mat[row][col] ==0){
        return;
    }

    mat[row][col] = 0;
    curr_path.push_back(mat[row][col]);
    getPath(mat, row +1, col, m, n, ans,curr_path);

     curr_path.push_back(mat[row][col]);
    getPath(mat, row, col +1, m, n, ans,curr_path);

}

int main(){
    int m,n;
    cout<<"enter m : ";
    cin>>m;
    cout<<"enter n : ";
    cin>>n;

    int ans_size = max(m,n);

    vector<vector<int>> matrix(m,vector<int>(n));
    vector<vector<int>> ans(ans_size, vector<int>(ans_size));
    vector<int> curr_path;

    for(int i = 0; i <m; i++){
        for(int j=0; j<n; j++){
            cin>> matrix[i][j];
        }
    }

  
    getPath(matrix, 0, 0, m, n, ans, curr_path);

      for(int i = 0; i <ans_size; i++){
         
        for(int j=0; j<ans_size; j++){
            cout<< ans[i][j]<<" ";
        }
        cout<<endl;
    }
}