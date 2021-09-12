#include<iostream>
using namespace std;


int count = 0;


string swap(string str, int i, int j){
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    return str;
}



void getPurumtation(string str, int index){

    if(index ==str.length()-1){
        count ++;
        cout<<str<<endl;
        return;
    }

    for(int i = index; i<str.length(); i++){
        string swapedString = swap(str, i, index);
        getPurumtation(swapedString, index+1);
        swap(str, i, index);
    }
}

int main(){
    string str = "akash";
    getPurumtation(str,0);

}