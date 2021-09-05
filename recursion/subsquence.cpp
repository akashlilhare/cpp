#include<bits/stdc++.h>
using namespace std;


void getSubSequence(vector<char> input, vector<char> output, int index){
    if(input.size()-1 <index){
        cout<<"{";
        for(auto i : output){
            cout<<i <<",";
        }
        cout<< "}";
        return;
    }

    getSubSequence(input, output, index +1);

    output.push_back(input[index]);

    getSubSequence(input, output, index+1);
}

int main(){
    vector<char> input = {'a','b','c'};
    vector<char> output = {};
    getSubSequence(input, output, 0);
}