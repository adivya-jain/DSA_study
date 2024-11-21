class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, (vector<int>(n, -1)));
        for (auto wall : walls) {
            grid[wall[0]][wall[1]] = 2;
        }
        for (auto& guard : guards) {
            grid[guard[0]][guard[1]] = 3;
        }

        for (auto guard : guards) {
            int r = guard[0];
            int c = guard[1];

            // up
            for (int i = r - 1; i >= 0 && grid[i][c] != 2 && grid[i][c] != 3; --i)
                grid[i][c] = 0;

            // Move down
            for (int i = r + 1; i < m && grid[i][c] != 2 && grid[i][c] != 3; ++i)
                grid[i][c] = 0;

            // Move left
            for (int j = c - 1; j >= 0 && grid[r][j] != 2 && grid[r][j] != 3; --j)
                grid[r][j] = 0;

            // Move right
            for (int j = c + 1; j < n && grid[r][j] != 2 && grid[r][j] != 3; ++j)
                grid[r][j] = 0;
        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == -1)
                    count++;
            }
        }
        return count;
    }
};