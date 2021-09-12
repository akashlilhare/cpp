
#include<bits/stdc++.h>
using namespace std;

    void path(vector<vector<int>> &m, int n, int x, int y, vector<string> &ans, string curr_path){      
        if(x == n || y == n || x <0 || y <0){
            return;
        }

        if(m[x][y] == 0){
            return;
        }

        if( x == n-1 && y == n-1){
            ans.push_back(curr_path);
            return;
        }
        
        m[x][y] = 0;
        curr_path += 'D';
        path(m, n, x+1, y,ans, curr_path);
        
        curr_path += 'U';
        path(m, n, x-1, y,ans, curr_path);
              
        curr_path += 'R';
        path(m, n, x, y+1, ans, curr_path);
          
        curr_path += 'L';
        path(m, n, x, y-1, ans, curr_path);
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
       path(m, n, 0, 0, ans, "");
       
       
       return ans;
    }


int main(){
    
    vector<vector<int>> m = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}};

     vector<string> ans =  findPath(m,4);

     for(auto i : ans){
         cout<<i;
     }
}