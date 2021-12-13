#include<bits/stdc++.h>
using namespace std;

 vector<int> decimalToBinary(int n){
    vector<int> ans ;
    while (n>0){
        int temp = n%2;
        ans.push_back(temp);
        n = n/2;      
    }
    return ans;  
}

int binaryToDecimal(vector<int> input){
    int ans=0;

    for(int i =0; i<input.size(); i++){
        ans += input[i] * pow(2,i);
    }

return ans;
}

int main(){

    // int n ;
    // cin>>n;

    // vector<int> DCB = decimalToBinary(n);
    // for(int i=DCB.size()-1; i >=0; i--){
    //     if(DCB[i]==1){
    //         DCB[i] = 0;
    //     }else{
    //         DCB[i] = 1;
    //     }
    // }

    // int BTD = binaryToDecimal(DCB);
    // cout<<"ans: "<<BTD;


char input ;
cin>>input;

int in = input;
cout<<in;

}