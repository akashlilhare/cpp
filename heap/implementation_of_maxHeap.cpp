/*
Building Heap from Array


 Last Updated : 19 May, 2020
Given an array of N elements. The task is to build a Binary Heap from the given array. The heap can be either Max Heap or Min Heap.

Example:

Input: arr[] = {4, 10, 3, 5, 1}
Output: Corresponding Max-Heap:
       10
     /   \
    5     3
   /  \
  4    1

*/


#include<bits/stdc++.h>
using namespace std;

void hefify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2 * i + 2; 

    if(l<n && arr[largest] < arr[l])
        largest = l;
    
    if(l<n && arr[largest] < arr[r])
        largest =r;

    if(largest != i){
        swap(arr[i], arr[largest]);

        hefify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n){
    int startIdx = (n/2)-1;

    for(int i=startIdx; i>=0; i--){
        hefify(arr,n,i);
    }
}

void printHeap(int arr[], int n){
    cout<<"Array representation of heap is : \n";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 }; 
    int n = sizeof(arr)/sizeof(arr[0]);
    buildHeap(arr,n);
    printHeap(arr,n);

    return 0;
}