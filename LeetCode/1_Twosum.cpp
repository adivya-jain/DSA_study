class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> num_with_index;
        for (int i = 0; i < nums.size(); i++) {
            num_with_index.push_back({nums[i], i});
        }
        sort(num_with_index.begin(), num_with_index.end());

        int start = 0;
        int end = nums.size()-1;

        while(start <= end)
        {
            int sum = num_with_index[start].first + num_with_index[end].first;
            if(sum > target)
            {
                end--;
            }else if(sum < target)
            {
                start ++;
            }
            else
            {
                return {num_with_index[start].second, num_with_index[end].second};
            }
        }

        return{-1,-1};
    }
};