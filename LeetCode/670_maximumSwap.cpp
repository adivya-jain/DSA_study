class Solution {
public:
    int maximumSwap(int num) {
        string nums = to_string(num);
        vector<int> index(nums.size());
        index[nums.size() - 1] = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] > nums[index[i + 1]]) {
                index[i] = i;
            } else {
                index[i] = index[i + 1];
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums[index[i]]) {
                swap(nums[i], nums[index[i]]);
                break;
            }
        }
        
        return stoi(nums);;
    }
};