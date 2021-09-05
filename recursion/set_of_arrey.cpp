#include<bits/stdc++.h>
using namespace std;


// void subset(vector<int> input, vector<int> output, int index){

//     if(index > 2){
//         cout<<"{";
//         for(auto i : output){
//             cout<<i<<",";
//         }
//         cout<<"}";

//         return;
//     }

//     subset(input,output, index+1);
//      output.push_back(input[index]);

//     subset(input,output, index+1);
// }

// int main(){

// vector<int> input = {1,2,3};
// vector<int> output= {};
//    subset(input,output, 0);

// }



void getSubSet(vector<int>input, vector<int> output, int index){
    if(index >input.size()-1){
        cout<<"{";
        for(auto i : output){
            cout<<i<<",";
        }
        cout<<"}";
        return;
    }

    getSubSet(input, output, index+1);

    output.push_back(input[index]);

    getSubSet(input, output, index+1);
}


int main(){
    int n;
    cout<<"enter the size of arrey";
    cin>>n;
    vector<int> input(n);
    vector<int> output = {};
    for(int i=0; i<n; i++){
        cin>>input[i];
    }
    getSubSet(input, output, 0);
}