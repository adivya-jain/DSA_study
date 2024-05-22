// GFG https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

// The Celebrity Problem

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            st.push(i);
        }
        
        while(st.size() > 1 )
        {
            int A = st.top();
            st.pop();
            
            int B = st.top();
            st.pop();
            
            
            if(M[A][B] == 1)
            {
                st.push(B);
            }
            else{
                st.push(A);
            }
        }
        
        int ans = st.top();
        int count = 0 ;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(M[ans][i] == 0)
            {
                count++;
            }
        }
        
        if(count != n)
        {
            return -1;
        }
        
        
        count = 0;
        
        for(int i=0 ; i<n ; i++)
        {
            if(M[i][ans] == 1)
            {
                count++;
            }
            
        }
        if(count != n-1)
        {
            return -1;
        }
        
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends