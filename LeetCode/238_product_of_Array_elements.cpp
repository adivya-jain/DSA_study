class Solution {
public:
    void solve(vector<int>& nums) {
        int product = 1;
        int zerocunt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                product *= nums[i];
            else
                zerocunt++;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (zerocunt > 1) {
                nums[i] = 0;
            } else if (zerocunt == 1) {
                if (nums[i] != 0)
                    nums[i] = 0;
                else
                    nums[i] = product;
            } else
                nums[i] = product / nums[i];
        }
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        solve(nums);
        return nums;
    }
};