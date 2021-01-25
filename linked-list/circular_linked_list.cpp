
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

void insertAtHead(node* &head, int val){
   node* n = new node(val);
   if(head == NULL){
      head = n;
      n->next = head;
      return;
    }

    node* temp = head;

    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
    head = n;
}
void insertAtTail(node* &head, int val){

    node* n = new node(val);

    if(head == NULL){
        insertAtHead(head,val);
        return;
    }

    node* temp = head;

    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;

}

void deleteAtHead(node* &head){
 node* toDelete = head;
 
 node* temp = head;
 while(temp->next != head){
     temp = temp->next;
 }

 temp->next = head->next;
 head = head->next;

 delete toDelete;
}

void deletion(node* &head, int pos){
    node* temp = head;
    int count =1;

    if(pos ==1){
        deleteAtHead(head);
        return;
    }

    while(count != pos-1){
        temp = temp->next;
        count++;
    }

    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;

}

void display(node* head){

    node* temp = head;

    do{
        cout<<temp->data<<"->";
        temp = temp->next;
    }while(temp != head);
    cout<<"null";
}

int main(){
    int n;
    cout<<"enter number of element : ";
    cin>>n;
    node* head = NULL;
    for(int i=0; i<n; i++){
        int val;
        cout<<"enter element "<<i+1<<" : ";
        cin>>val;
        insertAtTail(head, val);
    }
    display(head);
    cout<<endl;
    deletion(head,5);
    display(head);
    cout<<endl;
    deleteAtHead(head);
    display(head);
}