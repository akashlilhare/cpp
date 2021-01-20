/*
A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Example 1:

Input:
LinkedList: 4->5->6
Output: 457 

*/

//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 

Node* addOne(Node *head);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        
        head = addOne(head);
        printList(head); 
    }
    return 0; 
} 
// } Driver Code Ends


//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

Node* reverse(Node *head){
    Node *prev =NULL;
    Node *curr =head;
    Node *nxt = NULL;
    
    while(curr != NULL){
       nxt = curr->next;
       curr->next = prev;
       prev = curr;
       curr = nxt;
    }
    
    return prev;
}
Node* addOne(Node *head) 
{
   Node* n = reverse(head);
   Node* temp = n;
   int carry =0;
   while(temp){
       if(n== temp){
           temp->data +=1;
           if(temp->data == 10){
               carry = 1;
               temp->data =0;
           }
       }else {
           temp->data = temp->data +carry;
           if(temp->data == 10){
               temp->data =0;
               carry =1;
           }else{
               carry =0;
           }
       }
       
       if(temp->next == NULL and carry ==1){
             Node* n = new Node(0);
             temp->next = n;
         }
       
       temp = temp->next;
   }
   return (reverse(n));
}