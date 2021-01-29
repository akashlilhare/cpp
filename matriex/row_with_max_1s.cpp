/*
Row with max 1s 

Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

Example 1:

Input: 
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based
indexing).

*/

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++
class Solution{
public:

int rowWithMax1s(vector<vector<int>> arr, int n, int m){
    
    int ans =-1;
    int r = m-1;
    int l=0;
    
    while(l <n and r>=0){
        if(arr[l][r] == 1){
            ans = l;
            r --;
        }else{
            l++;
        }
    }
    return ans;
}

// BrutForce approch
// 	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
//     int max1=0;
//     int ans =-1;
//     for(int i=0; i<n; i++){
//         int count =0;
//         for(int j=0; j<m; j++){
//             if(arr[i][j] == 1){
//                 count ++;
//             }
//         }
//         if(count > max1)
//             ans = i;
//     max1 = max(max1,count);
//     }
//     return ans;
// 	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends