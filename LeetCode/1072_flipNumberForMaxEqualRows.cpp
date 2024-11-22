class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int ans=0;
        int r = matrix.size();
        int c = matrix[0].size();
        for(auto mat:matrix)
        {
            int count = 0;
            vector<int> inverted(c);
            for(int i=0;i<c;i++)
            {
                inverted[i] = mat[i]==1?0:1;
            }

            for(auto m:matrix)
            {
                if(m==mat || m==inverted)
                {
                    count++;
                }
            }
            ans = max(ans,count);
        }
        return ans;
    }
};