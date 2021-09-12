
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n =5;
    int arr[n][n];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<< " ";
        }
        cout<<endl;
    }
    
    memset(arr, -1, sizeof(arr));
    
   for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<< " ";
        }
        cout<<endl;
    }
}
