class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int col = matrix[0].size();
        int row = matrix.size();
        vector<int> mini(row,INT_MAX);
        vector<int> maxi(col,INT_MIN);

        for (int i = 0; i < row; i++) {
            
            for (int j = 0; j < col; j++) {
               mini[i] = min(mini[i],matrix[i][j]);
               maxi[j] = max(maxi[j],matrix[i][j]);
            }
        }

     vector<int> ans;
        for (int i = 0; i < mini.size(); i++) {
            int element = mini[i];
            vector<int>::iterator it = find(maxi.begin(),maxi.end(),element);
            if (it!=maxi.end()) {
                ans.push_back(element);
            }
            
        }

        return ans;
    }
};