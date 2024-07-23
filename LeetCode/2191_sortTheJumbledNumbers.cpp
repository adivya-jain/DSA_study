class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> mappedNums;
        
        for (int i = 0; i < nums.size(); i++) {
            int value = nums[i];
            if (value == 0) {
                mappedNums.push_back({mapping[0], i});
                continue;
            }

            int output = 0, multiplier = 1;
            while (value > 0) {
                int digit = value % 10;
                output += mapping[digit] * multiplier;
                value /= 10;
                multiplier *= 10;
            }
            
            mappedNums.push_back({output, i});
        }
        
        sort(mappedNums.begin(), mappedNums.end());
        
        vector<int> final;
        for (const auto& p : mappedNums) {
            final.push_back(nums[p.second]);
        }
        
        return final;
    }
};
