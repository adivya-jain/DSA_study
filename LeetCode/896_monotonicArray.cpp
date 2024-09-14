class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int f=0;

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1] < nums[i])
            {
                f=1;
                break;
            }
        }
        if(f==0) return true;
        f=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1] > nums[i])
            {
                f=0;
                break;
            }
        }
        if(f==1) return true;
        return false;

    }
};