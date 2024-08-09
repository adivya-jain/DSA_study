class Solution {

    bool isSafe(map<int, bool>& rmap, map<int, bool>& d1map,
                map<int, bool>& d2map, int row, int col, int n) {
        if (rmap[row])
            return false;
        if (d1map[row + col])
            return false;
        if (d2map[n - 1 + col - row])
            return false;
        return true;
    }
    void reverse(map<int, bool>& rmap, map<int, bool>& d1map,
                 map<int, bool>& d2map, int row, int col, int n) {
        rmap[row] = !rmap[row];
        d1map[row + col] = !d1map[row + col];
        d2map[n - 1 + col - row] = !d2map[n - 1 + col - row];
    }
    void addSolution(vector<vector<string>>& ans,
                     vector<vector<string>>& result) {
        vector<string> solution;
        for (int i = 0; i < ans.size(); i++) {
            string temp;
            for (int j = 0; j < ans[0].size(); j++) {
                temp += ans[i][j];
            }
            solution.push_back(temp);
        }
        result.push_back(solution);
    }

    void solve(int col, int n, map<int, bool>& rmap, map<int, bool>& d1map,
               map<int, bool>& d2map, vector<vector<string>>& ans,
               vector<vector<string>>& result) {

        if (col == n) {
            addSolution(ans, result);
            return;
        }

        // solve 1 case else cases recusrion will handle
        for (int row = 0; row < n; row++) {
            if (isSafe(rmap, d1map, d2map, row, col, n)) {
                ans[row][col] = 'Q';
reverse(rmap, d1map, d2map, row, col, n);
                solve(col + 1, n, rmap, d1map, d2map, ans, result);
                ans[row][col] = '.';
                reverse(rmap, d1map, d2map, row, col, n);
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        map<int, bool> rmap;
        map<int, bool> d1map;
        map<int, bool> d2map;
        vector<vector<string>> ans(n, vector<string>(n, "."));
        vector<vector<string>> result;
        solve(0, n, rmap, d1map, d2map, ans, result);
        return result;
    }
};