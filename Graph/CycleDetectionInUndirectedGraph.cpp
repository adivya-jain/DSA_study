#include <unordered_map>
#include <queue>
bool isCycleBFS(int src,unordered_map<int,vector<int>> &adj,unordered_map<int,bool> &visited)
{
    unordered_map<int,int> parent;
    parent[src] = -1;
    visited[src] = 1;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        for(auto neighbour:adj[front])
        {
            if(visited[neighbour]==true && neighbour!=parent[front])
            {
                return true;
            }
            else if(!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour]=1;
                parent[neighbour] = front;
            }
        }
    }

    return false;
}
bool isCycleDFS(int node,int parent,unordered_map<int,vector<int>> &adj,unordered_map<int,bool> &visited)
{
    visited[node] = true;

    for(auto neighbour:adj[node])
    {
        if(!visited[neighbour])
        {
            bool isCyclePresent = isCycleDFS(neighbour,node,adj,visited);
            if(isCyclePresent) return true;
        }
        else if(neighbour!=parent)
        {
            return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int,vector<int>> adj;
    for(auto it:edges)
    {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,bool> visited;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            // bool ans = isCycleBFS(i,adj,visited);
            bool ans = isCycleDFS(i,-1,adj,visited);
            if(ans == 1) return "Yes";
        }
    }
    return "No";
    
}
