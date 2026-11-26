class Solution {
public:
    void bfs(int i,int j,int n,int m,vector<vector<char>>&grid)
    {
        grid[i][j]='0';

        if(i+1<m && grid[i+1][j]=='1'){
            bfs(i+1,j,n,m,grid);
        }
        
        if(j+1<n && grid[i][j+1]=='1'){
            bfs(i,j+1,n,m,grid);
        }
        
        if(i-1>=0 && grid[i-1][j]=='1'){
            bfs(i-1,j,n,m,grid);
        }
        
        if(j-1>=0 && grid[i][j-1]=='1'){
            bfs(i,j-1,n,m,grid);
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans=0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j]=='1')
                {
                    ans++;
                    bfs(i,j,n,m,grid);
                }
            }
        }
        return ans;
    }
};