#include<bits/stdc++.h>
using namespace std;

void merge(int A[], int front,int mid, int rear){
    int left_idx = (mid - front) +1;
    int right_idx = rear - mid;

    vector<int> left_sub_arr(left_idx);
    vector<int> right_sub_arr(right_idx);

    for(int i=0; i<left_idx; i++){
        left_sub_arr.at(i) =A[front+i];
    }

    for(int i=0; i<right_idx; i++){
        right_sub_arr.at(i) = (A[mid+1+i]);
    }

    int i=0, j=0, k=front;

    while(i <left_idx && j<right_idx){
        if(left_sub_arr[i] < right_sub_arr[j]){
            A[k] = left_sub_arr[i];
            i++;
            k++;
        }else{
            A[k] = right_sub_arr[j];
            j++;
            k++;
        }
    }

    while(i < left_idx){
        A[k] = left_sub_arr[i];
        i++;
        k++;
    }

    while(j < right_idx){
        A[k] = right_sub_arr[j];
        j++;
        k++;
    }
}

void mergesort(int A[], int front, int rear){
    if(front < rear){
        int mid = (front + rear)/2;
        mergesort(A,front, mid);
        mergesort(A,mid +1, rear);
        merge(A,front,mid,rear);
    }
}

int main(){
    int A[]={2,4,1,9,3,10,8,5,1,7};
    int n = sizeof(A)/sizeof(A[0]);
    mergesort(A,0, n);

   for(int i=0; i<n; i++){
       cout<<A[i]<<" ";
   }

}