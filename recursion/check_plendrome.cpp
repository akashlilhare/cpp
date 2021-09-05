#include<bits/stdc++.h>
using namespace std;


bool isPalndrome(string input, int front, int back){
    cout<<front<<" "<<back<<"\n";
    if(front == back){
        return true;
    }
    if(input[front] != input[back]){
        return false;
    }

    if(front < back)
     return  isPalndrome(input, front+1, back-1);
}

int main(){
    string input = "aakaa";
    if(isPalndrome(input, 0, input.size()-1)){
        cout<<"palindrome";
    }else{
        cout<<"not palindrome";
    }
}


