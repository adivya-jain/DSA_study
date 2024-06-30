class Solution {
public:
void dfs(int sv,vector<vector<int> > &v,vector<bool> &vis)
    {
        //cout<<sv<<endl;
        vis[sv]=true;
        for(int i=0;i<v[sv].size();i++)
        {
            if(vis[v[sv][i]])
                continue;
            dfs(v[sv][i],v,vis);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int> > ans(n),v(n);
        for(int i=0;i<edges.size();i++)
        {
            v[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i=0;i<n;i++)
        {
            vector<bool> vis(n,false);
            dfs(i,v,vis);
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                if(vis[j]) ans[j].push_back(i);
            }
        }
        return ans;
    }
};