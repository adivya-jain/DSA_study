class Solution {

    bool parity(int num) {
        if (num % 2) {
            return true;
        }
        return false;
    }

public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (parity(nums[i]) == parity(nums[i - 1])) {
                return false;
            }
        }
        return true;
    }
};