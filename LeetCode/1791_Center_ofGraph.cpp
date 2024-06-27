class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> pair1 = edges[0];
        vector<int> pair2 = edges[1];

        if(pair1[0] == pair2[0] || pair1[0] == pair2[1])
        {
            return pair1[0];
        }
        return pair1[1];
    }
};