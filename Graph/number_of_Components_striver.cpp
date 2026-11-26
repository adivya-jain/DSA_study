
class Solution {
public:
    void bfs(int i, queue<int>& que, vector<int> adj[], vector<int>& visited)
    {
        que.push(i);
        visited[i] = 1;

        while(!que.empty())
        {
            int node = que.front();
            que.pop();

            for(auto it : adj[node])
            {
                if(!visited[it])
                {
                    visited[it] = 1;
                    que.push(it);
                }
            }
        }
    }

    int findNumberOfComponent(int V, vector<vector<int>> &edges) {
        vector<int> visited(V, 0);
        queue<int> que;
        int ans = 0;

        vector<int> adj[V];

        for(int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                ans++;
                bfs(i, que, adj, visited);
            }
        }

        return ans;
    }
};
