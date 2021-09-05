#include<iostream>
using namespace std;

int fionacci(int n) {

    if(n ==1) return 1;

    if(n == 0) return 0;

    

    return fionacci(n-1) + fionacci(n-2);


}

int main(){
    int n;
    cout<<"enter number : ";
    cin>>n;
    cout<<"fibonaci of n : "<<fionacci(n);
}
