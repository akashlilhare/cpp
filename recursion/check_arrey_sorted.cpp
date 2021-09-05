
#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n, int i){

   if(i == n-1){
       return true;
   }

    if(arr[i] > arr[i+1]){
       return false;
   }
   return isSorted(arr, n , ++i);
}

int main(){

    int arr[] = {1,2,5,7,9};
    int arr2[]= {1,3,4,2,11};
    

    if(isSorted(arr2,5,0)){
        cout<<"arrey is sorted !";
    }else{
        cout<<"arrey is not sorted";
    }

}