class Solution {
public:
    int rowSum(vector<vector<int>>&grid, int r, int c) {
        int sum = 0;
        vector<int> visited(10, false);
        for (int i = 0; i < 3; i++) {
            
            int rowSum = 0; 
            for (int j = 0; j < 3; j++) {
                int val = grid[r + i][c + j];
                if (val >= 10 || val == 0 || visited[val]) {
                   return -1;
                }
                visited[val] = true;
                rowSum += val;
            }
            if (i == 0) {
                sum = rowSum;
            } else {
                if (sum != rowSum)
                    return -1;
            }
        }

        return sum;
    }
    int colSum(vector<vector<int>>&grid, int r, int c) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            int colSum = 0;
            for (int i = 0; i < 3; i++) {
                colSum += grid[r + i][c + j];
            }
            if (j == 0) {
                sum = colSum;
            } else {
                if (sum != colSum)
                    return -1;
            }
        }

        return sum;
    }
    int diagonalSum(vector<vector<int>>&grid, int r, int c) {
        int sum1 = grid[r][c] +grid[r+1][c+1]+ grid[r + 2][c + 2];
        // ommiting middle one for better accuracy
        int sum2 = grid[r][c + 2] +grid[r+1][c+1]+ grid[r + 2][c];
        if (sum1 != sum2)
            return -1;
        return sum1;
    }
    bool isValidMatirx(vector<vector<int>>&grid,int i,int j)
    {
        int rSum = rowSum(grid,i,j);
        if(rSum == -1) return false;
        int cSum = colSum(grid,i,j);
        if(cSum == -1) return false;
        if(rSum!=cSum) return false;

        int dSum = diagonalSum(grid,i,j);
        if(rSum!=dSum) return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        for (int i = 0; i < rows - 2; i++) {
            for (int j = 0; j < cols - 2; j++) {
                if (isValidMatirx(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};