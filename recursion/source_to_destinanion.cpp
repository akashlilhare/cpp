#include<bits/stdc++.h>
using namespace std;


class Offset{    
public:
    int x;
    int y;

    Offset(int x1, int y1){
       x = x1;
       y = y1;
    }
};

int totalPath = 0;
bool safe(int h, int w, Offset offset){
    if(offset.x <0 || offset.y >w){
        return false;
    }
    return true;
}

void getPath(int h, int w, Offset start, Offset end){

    if(!safe(h, w,start)){
        if(start.x <0){
            start.x-1;
        }else{
            start.y+1;
        }
        return;
    }

    if(start.x == end.x && start.y == end.y){
        totalPath ++;
        return;
    }

    getPath(h, w, Offset(start.x-1, start.y),end);

    getPath(h,w,Offset(start.x, start.y+1), end);

}

int main(){

 Offset start = Offset(2,0);
 Offset destination = Offset(0,3);

int h =2;
int w =3;

getPath(h, w, start, destination);

cout<<"toatal number of paths are : "<<totalPath;


}