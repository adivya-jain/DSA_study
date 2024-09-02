#include <unordered_map>
bool dfs(int i,unordered_map<int,bool>& visited,unordered_map<int,bool> &dfsvisited,unordered_map<int,vector<int>> &adj)
{
  visited[i]=true;
  dfsvisited[i]=true;
  for(auto neighbour:adj[i])
  {
    if(!visited[neighbour])
    {
    bool isCyclePresent = dfs(neighbour, visited,dfsvisited, adj);
    if(isCyclePresent) return true;
    }
    else if(dfsvisited[neighbour])
    {
      return true;
    }
  }
  dfsvisited[i]=false;
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int,bool> visited;
  unordered_map<int,bool> dfsvisited;
  unordered_map<int,vector<int>> adj;
  
  for(int i=0;i<edges.size();i++)
  {
    adj[edges[i].first].push_back(edges[i].second);
  }

  for(int i=1;i<=n;i++)
  {
    if(!visited[i])
    {
      int ans = dfs(i,visited,dfsvisited,adj);
      if(ans) return true;
    }

  }
  return false;

}