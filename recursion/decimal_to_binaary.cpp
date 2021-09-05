#include<bits/stdc++.h>
using namespace std;

void decimalToBinary(int num){
    
    if(num == 0 || num == 1){
        cout<<num;
        return;
    }

    
  

    decimalToBinary(num/2);
    cout<<num%2;


}

int main(){
    int num = 250;
    decimalToBinary(num);
}