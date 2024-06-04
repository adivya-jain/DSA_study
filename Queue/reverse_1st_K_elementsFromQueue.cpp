//{ Driver Code Starts
// Initial Template for C++
// Reverse First K elements of Queue
//  gfg
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        
        
        stack<int> st;
        
        
        for(int i =0;i<k;i++)
        {
            int front = q.front();
            st.push(front);
            q.pop();
        }
        
        while(!st.empty())
        {
            int top = st.top();
            q.push(top);
            st.pop();
        }
        
        int n = q.size();
        
        for(int i=0;i<n-k;i++)
        {
            
            int front = q.front();
            q.push(front);
            q.pop();
        }
        
        return q;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends