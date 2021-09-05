#include<bits/stdc++.h>
using namespace std;

class node{
public:
    node* next;
    int data;
    node(int val){
        data = val;
        next =NULL;
    }
};

void inserAtHead(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    n->next = head;
    head = n;
}


void inserAtTail(node* &head, int val){
    node* n = new node(val);

    if(head == NULL){
        head = n;
        return;
    }

    node* temp = head;

    while(temp->next){
        temp = temp->next;
    }

    temp->next = n;

}

bool seach(node* head, int key){
    while(head){
        
        if(head->data == key){
            return true;
        }
        head = head->next;
    }
    return false;
}

void print(node* head){
    while (head){
        cout<<head->data<<" ";
        head = head->next;
    }   
}

node* llReversal(node* head){
    node* reversed = NULL;
    while(head){
        inserAtHead(reversed, head->data);
        head = head->next;
    }
    return reversed;
}

node* reverse(node* &head){
    node* prevPtr = NULL;
    node* currPtr = head;
    node* nextPtr = NULL;

    while(currPtr){
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    return prevPtr;
}

node* reverseRecurcive(node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    node* newHead = reverseRecurcive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

node* mergeLL(node* &A, node* &B){
    if(A == NULL){
        return B;
    }

    if(B == NULL){
        return A;
    }

    if(A->data < B->data){
        A->next = mergeLL(A->next, B);
        return A;
    }else{
        B->next = mergeLL(B->next, A);
        return B;
    }
}

int main(){
   node* head1 = NULL;
   node* head2 = NULL;
   vector<int> v1 = {1,8,22,40};
   vector<int> v2 = {4,11,16,20};

   for(auto i : v1){
       inserAtTail(head1,i);
   }

   for(auto i : v2){
       inserAtTail(head2,i);
   }

   print(mergeLL(head1, head2));


}

