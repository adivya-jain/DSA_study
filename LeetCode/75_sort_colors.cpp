// leetcode: problem no: 75. Sort Colors
//Dutch flag algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int traverse = 0;
        while (traverse <= right) {
            if (nums[traverse] == 0) {
                swap(nums[left], nums[traverse]);
                left++;
                traverse++;
            } else if (nums[traverse] == 2) {
                swap(nums[right], nums[traverse]);
                right--;
            } else
                traverse++;
        }
    }
};