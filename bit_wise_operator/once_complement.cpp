#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int size = 0;
    cin>>n;
    while(n!=0){
        size++;
        n = n>>1;
    }
    int mask = 0;
    while(size!=0){
    mask =    (mask<< 1) | 1;
        size --;
    }
   
    cout<< (~n & (mask));
}