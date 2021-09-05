
#include<bits/stdc++.h>
using namespace std;

string getWord(int n){
    if (n==0) return "zero";
    if (n==1) return "one";
    if (n==2) return "two";
    if (n==3) return "three";
    if (n==4) return "four";
    if (n==5) return "five";
    if (n==6) return "six";
    if (n==7) return "seven";
    if (n==8) return "eight";
    if (n==9) return "nine";

}

void speackNum(int num){
    if(num ==0){
        return;
    }

    int len = to_string(num).size();
    int divider = pow(10,len-1);
    int toPrint = num/divider;
    cout<<getWord(toPrint)<<" ";
     num = num - (toPrint*divider);
     speackNum(num);
}
int main(){

    speackNum(6925);
    return 0;

}