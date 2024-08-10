class Solution {
    bool isSafe(int row, int col, vector<vector<char>>& board, char val) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == val) // checking curr col
            {
                return false;
            }
            if (board[row][i] == val) // checking curr row
            {
                return false;
            }
            if (board[(i / 3) + (3 * (row / 3))][(i % 3) + (3 * (col / 3))] == val) {
                return false;
            }
        }
        return true;
    }
bool solve(vector<vector<char>>& board)
{
    for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                //cell empty
                if (board[row][col] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isSafe(row,col,board,ch)) {
                            board[row][col] = ch;
                            bool aageSolutionPossible = solve(board);
                            if(aageSolutionPossible)
                            {
                                return true;
                            }
                            else{
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
}
public:
    void solveSudoku(vector<vector<char>>& board) {

        solve(board);
    }
};