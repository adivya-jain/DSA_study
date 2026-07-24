class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> newarray(nums.begin() + n - k,nums.end());
        int j=n-1;
        for(int i = n-k-1;i>=0;i--)
        {   
            nums[j] = nums[i];
            j--;
        }
        for(int i=0;i<newarray.size();i++)
        {
            nums[i]  = newarray[i];
        }
    }
};