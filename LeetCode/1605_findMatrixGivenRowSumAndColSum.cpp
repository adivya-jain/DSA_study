class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int row = rowSum.size();
        int col = colSum.size();

        vector<vector<int>> ans(row, vector<int>(col,0));

        int r = 0;
        int c = 0;
        while(r<row && c<col)
        {
            int value = min(rowSum[r],colSum[c]);
            ans[r][c] = value;
            rowSum[r]-=value;
            colSum[c]-=value;

            if(rowSum[r] == 0)
            {
                r++;
            }
            else{c++;}
        }

        return ans;
  
        
    }
};