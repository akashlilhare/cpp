#include<bits/stdc++.h>
using namespace std;

int binerySearch(vector<int> input, int start, int end, int target){
    if(start > end){
        return -1;
    }

    int mid = (start + end)/2;
    if(input[mid] == target){
        return mid;
    }

    if(target < input[mid]){
      return  binerySearch(input, start, mid-1,target);
    }else{
     return  binerySearch(input,mid+1, end, target);
    }
}

int main(){
    vector<int> input {1,2,3,4,5,6,7,8,9,10};
   cout<<binerySearch(input,0, input.size(), 7) +1;
}