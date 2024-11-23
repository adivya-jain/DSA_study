class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> res(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = box[j][i];
            }
        }
        for (auto& row : res) {
            reverse(row.begin(), row.end());
        }
        for (int i = 0; i < m; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (res[j][i] == '.') {
                    int stoneRow = -1;
                    for (int k = j - 1; k >= 0; k--) {
                        if (res[k][i] == '*') {

                            break;
                        } else if (res[k][i] == '#') {
                            stoneRow = k;
                            break;
                        }
                    }
                    if (stoneRow != -1) {
                        res[j][i] = '#';
                        res[stoneRow][i] = '.';
                    }
                }
            }
        }
        return res;
    }
};