class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        if (nums.empty())
            return 0;
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        int count = 0;
        for (auto it : mp) {
            // it.second = it.second + increment;
            if (it.second <= 1) {

                continue;
            }

            int increment = it.second - 1;
            mp[it.first] = 1;
            it.second = 1;
            mp[it.first + 1] += increment;
            count = count + increment;
            // next ko increment krdo incremnet jitna

            // mp[it++].second+=increment;
        }

        return count;
    }
};