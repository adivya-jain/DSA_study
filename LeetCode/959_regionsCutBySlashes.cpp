class Solution {

    void dfs(int row, int col, vector<vector<int>>& mat, int n) {
        mat[row][col] = 1;
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int nrow = row + delr[k], ncol =col + delc[k];
            if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= n||
                mat[nrow][ncol] != 0)
                continue;
            dfs(nrow, ncol, mat, n);
        }
    }

public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();

        vector<vector<int>> mat(n * 3, vector<int>(n * 3, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/') {
                    mat[i * 3][j * 3 + 2] = 1;
                    mat[i * 3 + 1][j * 3 + 1] = 1;
                    mat[i * 3 + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    mat[i * 3][j * 3] = 1;
                    mat[i * 3 + 1][j * 3 + 1] = 1;
                    mat[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n * 3; i++) {
            for (int j = 0; j < n * 3; j++) {
                if (mat[i][j] == 0) {
                    count++;
                    dfs(i, j, mat, n * 3);
                }
            }
        }
        return count;
    }
};