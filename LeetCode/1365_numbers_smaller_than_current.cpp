class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> countsort(101,0);
        for(auto x:nums) countsort[x]++;
        for(int i=1;i<countsort.size();i++)
        {
            countsort[i]+=countsort[i-1];
        }
        for(int k=0;k<nums.size();k++)
        {
            if(nums[k]!=0)
            {
                nums[k] = countsort[nums[k]-1];
            }
        }
        return nums;
    }
};
