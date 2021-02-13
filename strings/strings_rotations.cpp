/*
A Program to check if strings are rotations of each other or not

Given a string s1 and a string s2, write a snippet to say whether s2 is a rotation of s1?
(eg given s1 = ABCD and s2 = CDAB, return true, given s1 = ABCD, and s2 = ACBD , return false)


AlgoSrithm: areRotations(str1, str2)

    1. Create a temp string and store concatenation of str1 to
       str1 in temp.
                          temp = str1.str1
    2. If str2 is a substring of temp then str1 and str2 are 
       rotations of each other.

    Example:                 
                     str1 = "ABACD"
                     str2 = "CDABA"

     temp = str1.str1 = "ABACDABACD"
     Since str2 is a substring of temp, str1 and str2 are 
     rotations of each other.

*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool stringRotation(string s1, string s2){
    if(s1.length() != s2.length())
        return true;
    int i=0;
    int j=s1.length()-1;
    while(i <=j){
        cout<<s1.substr(i,i+2) <<"   "<<s2.substr(j,j-2);
        if(s1.substr(i,i+2) != s2.substr(j,j-2))
            return false;
            i+=2, j-2;
    }
    return true;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
   cout<< stringRotation(s1, s2);
}