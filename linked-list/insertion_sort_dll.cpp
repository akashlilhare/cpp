/*
Sort a k sorted doubly linked list

Given a doubly linked list containing n nodes, where each node is at most k away from its target position in the list. The problem is to sort the given doubly linked list.
For example, let us consider k is 2, a node at position 7 in the sorted doubly linked list, can be at positions 5, 6, 7, 8, 9 in the given doubly linked list.

Examples:
Input: DLL: 3<->6<->12<->56<->8
    k =2;
output: 2<->3<->6<->8<->12<->56
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

// node *reverseDLL(node* &head){
//     node* current = head;

//     if(current == NULL or current->next == NULL){
//         node* pre = current->prev;
//         node* nxt = current->next;
//         current->next = pre;
//         current->prev = nxt;
//         return current;
//     }else{
//         node* pre = current->prev;
//         node* nxt = current->next;
//         current->next = pre;
//         current->prev = nxt;
//         reverseDLL(nxt);
//     }
// }

node* reverseDLL(node * head)
{
node* current = head;
if(current == NULL || current -> next == NULL)
{
node* next = current->next;
node* pre = current-> prev;
current -> next = pre;
current -> prev = next;
return current;
}
else
{
node* next = current->next;
node* pre = current-> prev;
current -> next = pre;
current -> prev = next;
reverseDLL(next);
}

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

   node* reversed =  reverseDLL(head);
    display(reversed);
    cout<<endl;
}