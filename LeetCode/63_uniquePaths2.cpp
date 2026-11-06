class Solution {
public:
    int solve(int m, int n,vector<vector<int>>&obstacleGrid) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        // if(obs)
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if(obstacleGrid[i][j] == 1)
                {
                    dp[i][j]=INT_MIN;
                    continue;
                }
                if (i == 0 && j == 0)
                    continue;
                if (i > 0 && obstacleGrid[i-1][j]!=1) {
                    dp[i][j] += dp[i - 1][j];
                }
                if (j > 0 && obstacleGrid[i][j-1]!=1) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1) return 0;
        if(obstacleGrid[m-1][n-1]==1) return 0;
        return solve(m - 1, n - 1,obstacleGrid);
    }
};class Solution {
public:
    int solve(int m, int n,vector<vector<int>>&obstacleGrid) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        // if(obs)
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if(obstacleGrid[i][j] == 1)
                {
                    dp[i][j]=INT_MIN;
                    continue;
                }
                if (i == 0 && j == 0)
                    continue;
                if (i > 0 && obstacleGrid[i-1][j]!=1) {
                    dp[i][j] += dp[i - 1][j];
                }
                if (j > 0 && obstacleGrid[i][j-1]!=1) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1) return 0;
        if(obstacleGrid[m-1][n-1]==1) return 0;
        return solve(m - 1, n - 1,obstacleGrid);
    }
};