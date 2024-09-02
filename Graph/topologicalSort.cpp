#include <bits/stdc++.h>

void toposort(int i, unordered_map<int,vector<int>>& adj,vector<bool>&visited,stack<int>&st)
{
    visited[i]=true;
    for(auto it:adj[i])
    {   
        if(!visited[it])
        {
            toposort(it, adj, visited, st);
        }
    }
    st.push(i);

}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<e;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    vector<bool> visited(v);
    stack<int> st;
    for(int i =0;i<v;i++)
    {
       if (!visited[i]) { 
            toposort(i, adj, visited, st);
        }
    }
    
    vector<int> ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}