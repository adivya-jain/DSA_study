class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int start = pow(10,4);
        int end = - pow(10,4);

        for (int i = 0; i < arrays.size(); i++) {
            int currSize = arrays[i].size();
            if(abs(start - arrays[i][0]) > abs(end - arrays[i][currSize-1]))
            {
                start = min(start, arrays[i][0]);
            }
            else{
                end = max(end, arrays[i][currSize - 1]);
            }
        }

        return end - start;
    }
};