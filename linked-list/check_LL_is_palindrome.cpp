/*
Check if Linked List is Palindrome


Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;


/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/*You are required to complete this method */

Node* reverse(Node* head){
   Node* prevptr = NULL;
   Node* currptr = head;
   Node* nextptr = NULL;
   
   while(currptr){
       nextptr = currptr->next;
       currptr->next = prevptr;
       prevptr = currptr;
       currptr = nextptr;
   }
   
   return prevptr;
}
bool isPalindrome(Node *head)
{
    
    stack<int> s;
    
    Node* temp = head;
      while(temp){
        s.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp){
        if(s.top() != temp->data)
            return false;
        s.pop();
        temp = temp->next;
    }
    
    return true;
}




