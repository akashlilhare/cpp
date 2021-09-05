#include<bits/stdc++.h>

using namespace std;

int expo(int m, int n){
    if(n ==0)
    return 1;


    int opt_sol = expo(m,n/2);
    if(n % 2 ==0){   
        return opt_sol * opt_sol;
    }else{
        return m *opt_sol * opt_sol;
    }   
}


int main(){
    cout<<expo(2,10);
}