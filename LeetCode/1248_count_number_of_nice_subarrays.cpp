class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;

        int oddCount = 0;
        int result = 0;

        for(int i = 0 ; i < nums.size();i++)
        {
            oddCount += (nums[i]%2);

            if(mp.count(oddCount-k))
            {
                result += mp[oddCount-k];
            }

            mp[oddCount]++;
        }

        return result;
    }
};