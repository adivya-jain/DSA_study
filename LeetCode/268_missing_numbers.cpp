class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<bool> arr(nums.size()+1,true);
        for (int i = 0; i < nums.size(); i++) {
            arr[nums[i]] = false;
        }

        for (int i = 0; i < arr.size(); i++) {
            if(arr[i]) return i;
        }
          return -1;
    }
};

//adding all numbers to calculate sum
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int actual = (n * (n+1)) / 2;

        for(int i=0;i<nums.size();i++)
        {
            sum +=nums[i];
        } 
        return actual - sum;
    }
};
