class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int MIN = arrays[0].front();
        int MAX = arrays[0].back();
        int result = 0;
        for (int i = 1; i < arrays.size(); i++) {
            int currStart = arrays[i].front();
            int currEnd = arrays[i].back();
            result = max({result,abs(currStart - MAX),abs(currEnd - MIN)});
            MAX = max(MAX,currEnd);
            MIN = min(MIN,currStart);
        }

        return result;
    }
};