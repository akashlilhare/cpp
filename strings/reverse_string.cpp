/*
Write a function that reverses a string. 
The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying
the input array in-place with O(1) extra memory.

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int start =0;
        int end = s.size()-1;
        while(start<=end){
            char ch = s[start];
            s[start] = s[end];
            s[end] = ch;
            end--;
            start++;
        }
    }
};

int main(){
    Solution sol;
    vector<char> stringVec{'a','k','a','s','h'};

sol.reverseString(stringVec);
for(auto ch : stringVec){
    cout<<ch;
}

}

