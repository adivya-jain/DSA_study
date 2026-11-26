class Solution {
public:

    void bfs(int node,int n,vector<int>&visited,vector<vector<int>>& isConnected)
    {
        visited[node] = 1;
        for(int i=0;i<n;i++)
        {
            if(isConnected[node][i] && !visited[i])
            {
                visited[i]=1;
                bfs(i,n,visited,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();
        vector<int> visited(n+1,0);

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                ans++;
                bfs(i,n,visited,isConnected);
            }
        }
        return ans;  
    }
};