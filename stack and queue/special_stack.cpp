/*
Special Stack

Design a data-structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. Your task is to complete all the functions, using stack data-Structure.


Example 1:

Input:
Stack: 18 19 29 15 16
Output: 15
Explanation:
The minimum element of the stack is 15.
*/


#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}// } Driver Code Ends




void push(stack<int>& s, int a){
	if(s.empty()){
	    s.push(a);
	}else{
	    int temp = s.top();
	    if(temp > a){
	        s.push(a);
	    }else{
	        s.pop();
	        s.push(a);
	        s.push(temp);
	    }
	}
}

bool isFull(stack<int>& s,int n){
	if(s.size() == n)
	    return true;
	return false;
}

bool isEmpty(stack<int>& s){
	return s.empty();
}

int pop(stack<int>& s){
	 s.pop();
}

int getMin(stack<int>& s){
    if(s.empty())
        return -1;
	return s.top();
}