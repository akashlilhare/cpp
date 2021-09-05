#include<iostream>
using namespace std;

int print_n_to_1(int n) {
    if(n == 0) return n;

print_n_to_1(n-1);
    cout<<n<<" ";
 

    

}

int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    print_n_to_1(n);
}