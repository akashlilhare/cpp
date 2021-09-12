#include<bits/stdc++.h>
using namespace std;

string swapstr(string str, int i, int j){
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    return str;
}

void permutaion(string str, int index){
    if(index == str.length()-1){
        cout<<str<<" ";
        return;
    }

    for(int i = index; i<str.length(); i++){
        string swapedString = swapstr(str, i, index);
        permutaion(swapedString, index+1);
        swapstr(str, i, index);
    }
}

int main(){
    string input = "abc";
    permutaion(input, 0);
}