class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr = nums;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(arr[j]<arr[j+1])
                {
                    continue;
                }else{
                    if(__builtin_popcount(nums[j]) == __builtin_popcount(nums[j+1]))
                    {
                        swap(arr[j],arr[j+1]);
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};