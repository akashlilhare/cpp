/*
Find pairs with given sum in doubly linked list

Example:  

Input : head : 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
        x = 7
Output: (6, 1), (5,2)


*/

#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }  
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    if(head != NULL){
         head->prev = n;
    }
    head = n;
}
void insertAtTail(node* &head, int val){

    if(head == NULL){
        insertAtHead(head, val);
        return;
    }

    node* n = new node(val);
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void deletionAtHead(node* &head){
    node* todelete = head;
    head = head->next;
    head->prev = NULL;

    delete todelete;
}

void deletion(node* &head){
    int pos;
    cout<<"enter position : ";
    cin>>pos;

    node* temp = head;
    int count =1;

    if(pos == 1){
        deletionAtHead(head);
        return;
    }
    while(temp != NULL and count!=pos){
        count++;
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }
    delete(temp);
}

void display(node* head){

    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"null";
}

node *getTail(node *head){
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    return temp;
}

int pairSum(node *head, int x){
    node* tail = getTail(head);
    int count = 0;
    while(head != tail){
        int sum = head->data + tail->data;
        if(sum == x){
            cout<<head->data<<" "<<tail->data<<endl;
            count++;
            head = head->next;
            tail = tail->prev;
        }else if(sum < x){
            head->next;
        }else{
            tail = tail->prev;
        }
    }
    return count;
}

int main(){
    node* head = NULL;
    int n;
    cout<<"enter number of elements : ";
    cin>>n;

    for(int i=0; i<n; i++){
        int val;
        cout<<"enter element "<<i+1<<" : ";
        cin>>val;
        insertAtTail(head, val);
    }

    display(head);
    cout<<endl;

    cout<<pairSum(head, 7);
}