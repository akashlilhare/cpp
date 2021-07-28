#include <bits/stdc++.h>
using namespace std;

int main(){
    string str = "test string ";
    map<char,int> count;

    for(int i =0; i< str.size(); i++){
        count[str[i]] ++;
    }

    for(auto i : count){
        if(i.first != ' ' && i.second >1){
            cout<<i.first<<" : "<<i.second<<endl;
        }
    }


}