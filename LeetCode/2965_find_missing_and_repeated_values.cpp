class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int m = grid.size();
        unordered_map<int,int> mp;
        

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {

                mp[grid[i][j]]++;
            }
        } 
        int missing = -1;
        int repeated = -1;
        for(int i=1;i<= m*m;i++)
        {
            if(mp[i] == 1)
            {
                continue;
            }
            else if(mp[i] == 2)
            {
                repeated = i;
                
            }
            else{
                 missing = i;
            }
        }
        return {repeated,missing};
    }
};
