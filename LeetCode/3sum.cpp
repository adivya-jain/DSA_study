class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int start = i+1;
            int end = n - 1;
            while (start < end) {
                 int total = nums[i] + nums[start] + nums[end];
                if (total == 0) {
                    vector<int> temp = {nums[i], nums[start], nums[end]};
                    result.push_back(temp);
                    start++;
                    while (nums[start] == nums[start-1] && start < end) {
                        start++;
                    }
                } else if (total > 0) {
                    end--;
                } else {
                    start++;
                }
            }
        }
        return result;
    }
};