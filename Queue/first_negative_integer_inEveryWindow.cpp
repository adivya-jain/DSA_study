//{ Driver Code Starts // First negative integer in every window of size k || gfg

#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) 
                                             
{
 deque<long long int> dq;
 vector<long long> ans;
 
 //process 1st window of k size
 
 for(int i=0;i<K;i++)
 {
     if(A[i]<0)
     {
         dq.push_back(i);
     }
 }
 //store answer of 1st window of k size
 if(dq.size()>0)
 {
     ans.push_back(A[dq.front()]);
 }
 else{
     ans.push_back(0);
 }
 
 //process the remaining window
 
 for(int i = K;i<N;i++)
 {
     if(!dq.empty() && i-dq.front() >=K)
     {
         dq.pop_front();
     }
     //addition
     
     if(A[i]<0)
     {
         
         dq.push_back(i);
     }
     
     //ans store
     
     
     if(dq.size() > 0)
     
     {
         ans.push_back(A[dq.front()]);
     }
     else{
         ans.push_back(0);
     }
 }
 return ans;
                                                 
                                                 
                                                 
}