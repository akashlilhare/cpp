#include<bits/stdc++.h>
using namespace std;

void hefify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n and arr[largest] < arr[l])
        largest = l;
    
    if(r<n and arr[largest] < arr[r])
        largest = r;

    
    if(largest != i){
        swap(arr[i], arr[largest]);
        hefify(arr,n,largest);
    }
}

void heapSort(int arr[], int n){
    for(int i=n/2-1; i>=0; i--){
        hefify(arr,n,i);
    }

    for(int i=n-1; i>0; i--){
        swap(arr[0], arr[i]);
        hefify(arr,i,0);
    }
}

void printHeap(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

     int arr[] = {4,1,3,9,7}; 
     int n = sizeof(arr)/sizeof(arr[0]);

     printHeap(arr,n);
     cout<<endl;
     heapSort(arr,n);

     printHeap(arr,n);

     return 0;

}