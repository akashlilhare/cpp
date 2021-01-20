// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

struct Node* addTwoLists(struct Node* first, struct Node* second);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
Node* reverseNode(struct Node* list){
    Node* prevptr = NULL;
    Node* currptr = list;
    Node* nextptr = NULL;
    while(currptr != NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

void push(Node* &head, Node* n){
    
 
    if(head == NULL){
        head = n;
        return;
    }
   Node* temp = head;    
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    temp->next = n;
    
}

void addNode(int s, Node* &head){
    Node* n = NULL;
    if( s>=10){
         n = new Node(s%10);
    }else{
         n = new Node(s);
    }
    
    push(head, n);
    
}

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    Node* ptr1;
    Node* start1;
    Node* ptr2; 
    Node* start2;
    start1 = reverseNode(first);
    start2 = reverseNode(second);
    int carry = 0;
    Node* resultHead = NULL;
    
    ptr1 = start1;
    ptr2 = start2;

    while(ptr1 and ptr2){
        int s = ptr1->data + ptr2->data +carry;
        addNode(s, resultHead);
        if(s >=10){
            carry = 1;
        }else{
            carry =0;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    while(ptr1){
        int s=0;
         s = ptr1->data + carry;
            addNode(s,resultHead);
        if(carry ==1){
           
            if(s>=10){
                carry =1;
            }else{
                carry =0;
            }
        }
        ptr1 =ptr1->next;
    }
    
    while(ptr2){
        int s=0;
            s = ptr2->data + carry;
            addNode(s,resultHead);
        if(carry ==1){
            if(s>=10){
                carry =1;
            }else{
                carry =0;
            }
        }
        ptr2 =ptr2->next;
    }
    
    if(carry == 1){
        addNode(1, resultHead);
    }
    
    return reverseNode(resultHead);
    
    
}









