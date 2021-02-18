#include<iostream>
#include<stack>
using namespace std;

class queue{
    stack<int> s1;
    stack<int> s2;

public:
    void push(int n){
        s1.push(n);
        cout<<"pushing "<<n<<" ..."<<endl;
    }

    void pop(){
        if(s1.empty()){
            cout<<"Queue is empty"<<endl;
        }
        while(! s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        cout<<"poping "<<s2.top()<<" ..."<<endl;
        s2.pop();
        while(! s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    bool empty(){
      return s1.empty();
    }
};

int main(){
    queue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout<<q.empty()<<endl;
    q.pop();

    q.pop();

    q.pop();
 
     cout<<q.empty()<<endl;

    return 0;
}