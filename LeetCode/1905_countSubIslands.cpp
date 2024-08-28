class Solution {
    bool solve(vector<vector<int>>& grid2, vector<vector<int>>& mix,
               vector<vector<int>>& visited, int i, int j, int rows, int cols) {
         if (i >= rows || i < 0 || j >= cols || j < 0 || visited[i][j] || grid2[i][j] == 0) {
            return true;
        }

        if (grid2[i][j] == 1 && mix[i][j] == 0)
            return false;

        visited[i][j] = 1;
        bool up = solve(grid2, mix, visited, i - 1, j, rows, cols);
        bool down = solve(grid2, mix, visited, i + 1, j, rows, cols);
        bool right = solve(grid2, mix, visited, i, j + 1, rows, cols);
        bool left = solve(grid2, mix, visited, i, j - 1, rows, cols);
        return up && down && right && left;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int rows = grid1.size();
        int cols = grid1[0].size();
        vector<vector<int>> mix(rows, vector<int>(cols, 0));
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                mix[row][col] = grid1[row][col] * grid2[row][col];
            }
        }
        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid2[i][j] == 1 && !visited[i][j]) {
                    bool isSubIsland =
                        solve(grid2, mix, visited, i, j, rows, cols);
                    if (isSubIsland) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};