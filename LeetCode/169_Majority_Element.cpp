class Solution {
public:
    bool isMajority(int cand, int size, vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (cand == nums[i]) {
                count++;
            }
        }

        if (count >= size / 2) {
            return true;
        }
        return false;
    }

    int getCndidate(vector<int>& nums, int size) {
        int maj_index = 0;

        int count = 1;
        for (int i = 1; i < size; i++) {
            if (nums[maj_index] == nums[i]) {
                count++;
            } else {
                count--;
            }

            if (count == 0) {
                maj_index = i;
                count = 1;
            }
        }
        return nums[maj_index];
    }

    int majorityElement(vector<int>& nums) {
        int arrsize = nums.size();

        int cand = getCndidate(nums, arrsize);

        // checking for majority
        if (isMajority(cand, arrsize, nums)) {
            return cand;
        }
        return -1;
    }
};