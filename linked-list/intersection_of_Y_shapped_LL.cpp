/*
Intersection Point in Y Shapped Linked Lists 
Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

 

Example 1:

Input:
LinkList1 = 3->6->9->common
LinkList2 = 10->common
common = 15->30->NULL
Output: 15
*/

#include<iostream>
#include<stdio.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
   
int count(Node* head){
    int l=1;
    while(head != NULL){
        head = head->next;
        l++;
    }
    return l;
}

int intersectPoint(Node* head1, Node* head2)
{
     int l1 = count(head1);
    int l2 = count(head2);
    int d;
    
    Node* n1;
    Node* n2;
    
    if(l1>l2){
        d = l1-l2;
        n1 = head1;
        n2 = head2;
    }else{
        d = l2-l1;
        n1 = head2;
        n2 = head1;
    }
    
    while(d){
        n1 = n1->next;
        if(n1 == NULL){
            return -1;
        }
        d--;
    }
    
    while(n1 != NULL and n2!=NULL){
        if(n1 == n2){
           return n1->data;
        }
        n1 = n1->next;
        n2 = n2->next;
    }
    return -1;
}




