class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) {
            return 0;
        }
        sort(nums.begin(), nums.end());
     
        //4 cases
        int ans = INT_MAX;
        //1st case all 3 largest element replaced with 4th largest element
        ans = min(ans,nums[n-4]-nums[0]);

        //2nd case-> 2 largest elements are replaced with 3rd largest 
        // and 1st smallest element is replaced with 2nd smallest elememt
        ans = min(ans,nums[n-3]-nums[1]);

        //3rd case , 2 smalles element is replaced with 3rd smallest and 
        //1 largest element is replaced with 2nd largest element
        ans = min(ans,nums[n-2]-nums[2]);

        //4th case , 3 smallest element replaced with 4th smallest element
        ans = min(ans,nums[n-1]-nums[3]);
        return ans;
    }
};