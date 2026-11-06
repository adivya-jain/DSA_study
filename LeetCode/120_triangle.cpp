class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& tri, int r,vector<vector<int>>&dp) {
       // Recursion will give TLE
        if (i == r)
            return tri[r][j];

        if(dp[i][j]!=-1) return dp[i][j];
        int d = tri[i][j] + solve(i + 1, j, tri, r,dp);
        int diag = tri[i][j] + solve(i + 1, j+1, tri, r,dp);
        return dp[i][j] = min(d, diag);
    }

    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        // int c = tri[n-1].size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return solve(0, 0, tri, n-1,dp);
        
        
        //bottom up approach
        // vector<vector<int>>dp(n,vector<int>(n,0));
        // for(int j = 0;j<n;j++)
        // {
        //     dp[n-1][j] = tri[n-1][j];
        // }
        // for(int i=n-2;i>=0;i--)
        // {
        //     for(int j=i;j>=0;j--)
        //     {
        //         int d = tri[i][j] + dp[i+1][j];
        //         int dg = tri[i][j]+ dp[i+1][j+1];
        //         dp[i][j]=min(d,dg);
        //     }
        // }
        // return dp[0][0];


        //bottom up space optimization approach
        // vector<int>dp(n,0);
        // for(int j = 0;j<n;j++)
        // {
        //     dp[j] = tri[n-1][j];
        // }
        // for(int i=n-2;i>=0;i--)
        // {
        //     for(int j=0;j<i;j--)
        //     {
        //         dp[j]=tri[i][j] + min(dp[j],dp[j+1]);
        //     }
        // }
        // return dp[0];

        for(int i=n-2;i>=0;i--)
        {
            for(int j = 0;j<=i;j++)
            {
                tri[i][j]+=min(tri[i+1][j],tri[i+1][j+1]);
            }
        }
        return tri[0][0];
    }
};
