class Solution {
    int solve(vector<vector<int>>& grid, int row, int r, int col, int c,
              int moves, int curr,vector<vector<int>>&dp) {
        if (r > row || r < 0 || c > col)
            return moves;
        if (curr >= grid[r][c]) {
            return moves;
        }
        if (dp[r][c] != -1)
            return dp[r][c];

        moves += 1;
        curr = grid[r][c];

        int up = solve(grid, row, r - 1, col, c + 1, moves, curr,dp);
        int samerow = solve(grid, row, r, col, c + 1, moves, curr,dp);
        int below = solve(grid, row, r + 1, col, c + 1, moves, curr,dp);
        dp[r][c] = max({up, samerow, below});
        return dp[r][c];
    }

public:
    int maxMoves(vector<vector<int>>& grid) {
        int row = grid.size() - 1;
        int col = grid[0].size() - 1;
        int longestmove = INT_MIN;
        vector<vector<int>> dp(row+1,vector<int>(col+1,-1));
        int c = 0;

        for (int r = 0; r <= row; r++) {
            // int curr = grid[c][r];
            int ans = solve(grid, row, r, col, c, 0, INT_MIN,dp);
            longestmove = max(longestmove, ans);
        }

        return longestmove - 1;
    }
};