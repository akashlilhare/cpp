#include<bits/stdc++.h>
using namespace std;

void reverseString(string str){

    if(str.size() == 0){
        return;
    }

    reverseString(str.substr(1,str.length()));
    cout<<str[0];

}

int main(){

    string str = "the simple engineer";

    reverseString(str);
}