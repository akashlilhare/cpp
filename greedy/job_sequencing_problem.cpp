/*
Job Sequencing Problem

Given a set of N jobs where each job i has a deadline and profit associated to it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the maximum profit and the number of jobs done.

Note: Jobs will be given in the form (Job id, Deadline, Profit) associated to that Job.


Example 1:

Input:
N = 4
Jobs = (1,4,20)(2,1,10)(3,1,40)(4,1,30)
Output:
2 60
Explanation:
2 jobs can be done with
maximum profit of 60 (20+40).
Example 2:

Input:
N = 5
Jobs = (1,2,100)(2,1,19)(3,2,27)
(4,1,25)(5,1,15)
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).

*/

// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
// Prints minimum number of platforms reqquired 

class Solution {
  public:
    static bool cmp(struct Job j1, struct Job j2){
        int a = j1.profit;
        int b = j2.profit;
        return a >b;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int> ans;
        int maxprofit = 0;
        sort(arr, arr+n, cmp);
        
        int deadmax = INT_MIN;


        for(int i=0; i<n; i++){
            deadmax = max(deadmax, arr[i].dead);
        }
        
        vector<bool> visited(deadmax,false);
        
        for(int i =0; i<n; i++){
           int j = arr[i].dead -1;
           while(j>=0){
               if(visited[j] == false){
                   visited[j] = true;
                   maxprofit += arr[i].profit;
                   break;
               }
               j--;
           }
        }
        
        int count =0;
        
        for(int i=0; i<deadmax; i++){
            if(visited[i] == true)
                count++;
        }
          ans.push_back(count);
          ans.push_back(maxprofit);
          
          return ans;
        
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}
