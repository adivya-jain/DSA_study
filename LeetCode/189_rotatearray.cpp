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

//method 2

class Solution {
public:

    void reverse(vector<int>& nums,int s, int n ,int k)
    {
        while(s<n)
        {
            swap(nums[s],nums[n]);
            s++;
            n--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size()-1;
        k = k%(n+1);
        reverse(nums,0,n,k);
        reverse(nums,0,k-1,k);
        reverse(nums,k,n,k);

        
    }
};