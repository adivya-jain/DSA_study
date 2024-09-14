class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = 0;
        for(int i=0;i<nums.size();i++)
        {
            maxi = max(maxi,nums[i]);
        }
        int cnt = 0;
        int ans=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==maxi)
                cnt++;
            else{
                cnt=0;
            }
            ans = max(ans,cnt);
        }

        return ans;
    }
};