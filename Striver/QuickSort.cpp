class Solution {
public:
    int partition(vector<int> &nums,int l,int r)
    {
        int pivot = nums[l];
        int left = l+1;
        int right = r;
        while(left <= right)
        {
            while(left <= r && pivot >= nums[left])
            {
                left++;
            }
            while(right >= l && pivot < nums[right])
            {
                right--;
            }
            if(left < right)
                swap(nums[left],nums[right]);
        }

        swap(nums[right],nums[l]);
        return right;
    }
    void applyquicksort(vector<int>& nums,int l,int r)
    {
        if(l >= r) return;
        int partitionIndex = partition(nums,l,r);
        applyquicksort(nums,l,partitionIndex-1);
        applyquicksort(nums,partitionIndex+1,r);
    }
    vector<int> quickSort(vector<int>& nums) {
        int n = nums.size();
        applyquicksort(nums,0,n-1);
        return nums;
    }
};
