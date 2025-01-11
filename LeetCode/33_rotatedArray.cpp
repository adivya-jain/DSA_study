class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (right + left) / 2;
            if (target == nums[mid])
                return mid;
            if (nums[left] <= nums[mid]) {
                if (target < nums[mid] && nums[left] <= target)
                    right = mid - 1;
                else
                    left = mid + 1;

            } else {
                if (nums[mid] < target && nums[right] >= target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};