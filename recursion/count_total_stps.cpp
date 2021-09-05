#include<bits/stdc++.h>
using namespace std;

int totalCount = 0;


void countSteps(int n){
    if(n == 0){
        totalCount ++;
        return;
    }

    if( n < 0){
        return;
    }
    

    for(int i =1; i<=3; i++){
        countSteps(n-i);
    }
}


int main(){
    int n;
    cout<<"enter total number of steps : ";
    cin>>n;

    countSteps(n);
    cout<<"total steps : " <<totalCount;
}