class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int ind = abs(nums[i]);
            if (nums[ind] < 0) {
                return ind;
            }
            nums[ind] = -nums[ind];
        }
        return -1;
    }
};


//approach 2 using visited array
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        for (int i = 0; i < nums.size(); i++) {
            if (visited[nums[i]]) {
                return nums[i];
            } else
                visited[nums[i]] = true;
        }
        return -1;
    }
};