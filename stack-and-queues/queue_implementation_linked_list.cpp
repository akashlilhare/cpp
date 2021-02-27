#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;     
    }
};

class  queue{
    node* front;
    node* back;

public:
    queue(){
        front = NULL;
        back = NULL;
    }
    void push(int x){
        node* n = new node(x);   
        if(front == NULL){
            front = n;
            back = n;
            return;
        }
        back->next = n;
        back =n;
    }

    void pop(){
        if(front == NULL){
            cout<<"queue underflow";
            return;
        }
        node* toDelete = front;
        front = front->next;

        delete toDelete;
    }

    int peak(){
        if(front == NULL){
            cout<<"queue underflow";
            return -1;
        }
        return front->data;
    }

    bool empty(){
        if(front == NULL){
            return true;
        }
        return false;
    }
};

int main(){
    queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout<<q.peak()<<endl;
    q.pop();
    cout<<q.peak()<<endl;
    q.pop();
    cout<<q.peak()<<endl;
    q.pop();
    cout<<q.empty()<<endl;
    cout<<q.peak()<<endl;
    q.pop();
    cout<<q.empty()<<endl;
}