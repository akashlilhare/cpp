/*
Middle of three

Given three distinct numbers A, B and C. Find the number with value in middle (Try to 
do it with minimum comparisons).

Input:
A = 978, B = 518, C = 300
Output:
518
Explanation:
Since 518>300 and 518<978, so 
518 is the middle element.

*/



#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    int middle(int A, int B, int C){
      if (A < B)
        return (B < C)? B : max(A, C);
      return (A < C)? A : max(B, C);
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.middle(A,B,C) <<"\n";
    }
    return 0;
} 