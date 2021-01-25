
/*
Count triplets in a sorted doubly linked list whose sum is equal to a given value x

Given a sorted doubly linked list of distinct nodes(no two nodes have the same data) and a value x. Count triplets in the list that sum up to a given value x.

Examples:

Input: DLL: 1<-> 2<-> 4 <-> 5 <-> 6 <-> 8 <-> 9
X =17

output : 2
(2,6,9) and (4,5,8)

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

int tripletSum(node* head, int x){
int count =0;
for(node* temp1 = head; temp1->next->next != NULL; temp1 = temp1->next){
    for(node* temp2 = temp1->next; temp2->next != NULL; temp2 = temp2->next){
        for(node* temp3 = temp2->next; temp3 != NULL; temp3 = temp3->next){
         //   cout<<temp1->data<<" "<<temp2->data<<" "<<temp3->data<<endl;
            if(temp1->data+temp2->data+temp3->data == x){
                cout<<temp1->data<<" "<<temp2->data<<" "<<temp3->data<<endl;
                count ++;
            }
        }
    }
}

return count;
}

int tripletSumMap(node* head, int x){

    unordered_map<int,node*> um;

    node *ptr, *ptr1, *ptr2;
    for(ptr = head; ptr != NULL; ptr = ptr->next){
       um[ptr->data] = ptr;
    }

    int count = 0;

    for(ptr1 = head; ptr1->next!= NULL; ptr1 = ptr1->next){
        for(ptr2 = ptr1; ptr1 != NULL; ptr2 = ptr2->next){

            int sum = ptr1->data+ptr2->data;
            if(um.find(x - sum) != um.end() and um[x-sum] != ptr1 and um[x-sum] != ptr2){
                count++;
            }
        }
    }
    return count/3;
}

node *getTail(node *head){
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    return temp;
}


int tripletSumTwoPointer(node *head, int x){
    node *tail = getTail(head);
    node *ptr1,  *ptr2;
    int count = 0;
    for(node* temp = head; temp != NULL; temp = temp->next){
        ptr1 = temp->next; ptr2 =tail;
        while(ptr1 != ptr2){
            int sum = temp->data + ptr1->data + ptr2->data;
            if(sum == x){      
                cout<<temp->data <<" "<< ptr1->data <<" "<< ptr2->data<<endl;
                count++; 
                 break;
                }            
            else if(sum < x){
                ptr1 = ptr1->next;
            }else{
                ptr2 = ptr2->prev;
            }
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

    cout<<"value = "<<tripletSumTwoPointer(head, 17);
}