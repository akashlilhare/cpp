/*
Search a 2D Matrix

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [
    [1,3,5,7],
    [10,11,16,20],
    [23,30,34,60]
    ],
     target = 3
Output: true
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      //  int n = matrix.size(), m =matrix[0].size();
      // cout<<m<<n;
        int row=0, col=matrix[0].size()-1;
        while(row<=matrix.size()-1 and col>= 0){
          //  cout<<matrix[row][col]<<" ";
            if(matrix[row][col] == target){
                return true;
            }else if(matrix[row][col] < target){
                row++;
            }else{
                col--;      
            }
        }
            return false;

    }
};

int main(){

    Solution sol = Solution();

    vector<vector<int>> mat =
  {
      {1,2,3,4},
      {5,6,7,8},
      {9,10,11,12},
      {13,14,15,16}
      };

      sol.searchMatrix(mat,10);
}