// SWEEP LINE ALGORTIHM
// AT ANY POINT OF TIME, WE CAN HAVE MULTIPLE INTERVALS ACTIVE
// WE NEED TO FIND THE MAXIMUM NUMBER OF ACTIVE INTERVALS AT ANY POINT OF TIME
// WE CAN DO THIS BY USING A PREFIX SUM ARRAY
// WE CAN INCREMENT THE PREFIX SUM ARRAY AT THE START OF THE INTERVAL AND DECREMENT IT AT THE END OF THE INTERVAL
// WE CAN THEN FIND THE MAXIMUM VALUE IN THE PREFIX SUM ARRAY


class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i = 0; i < intervals.size(); i++) {
            mini = min(mini, intervals[i][0]);
            maxi = max(maxi, intervals[i][1]);
        }
        vector<int> prefixSum(maxi + 2, 0);

        for (int i = 0; i < intervals.size(); i++) {
            prefixSum[intervals[i][0]]++;
            prefixSum[intervals[i][1] + 1]--;
        }
        int ans = 0;
        for (int i = mini; i < maxi + 2; i++) {
            prefixSum[i] = prefixSum[i] + prefixSum[i - 1];
            if (prefixSum[i] > ans)
                ans = prefixSum[i];
        }
        return ans;
    }
};