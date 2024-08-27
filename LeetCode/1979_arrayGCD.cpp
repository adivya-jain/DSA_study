class Solution {
    int solve(int a,int b)
    {
        if(a==0) return b;
        return solve(b%a,a);
    }
public:
    int findGCD(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
        }
        return solve(mini,maxi);
    }

};