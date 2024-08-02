class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // vector<int> temp = nums;
        int size = nums.size();
        int oneCount = 0;
        for (int i = 0; i < size; i++) {
   
                oneCount+=nums[i];
            
        }
        int zeroCount = 0;
        for (int i = 0; i < oneCount; i++) {
            if (nums[i] == 0)
                zeroCount++;
        }
        int mini = zeroCount;
        if (zeroCount == 0) {
            return 0;
        }
        int start = 0;
        int end = oneCount-1;
        while (start < size) {
            if (nums[start] == 0) {
                zeroCount--;
            }
            start++;
            end++;
            if (nums[end%size] == 0) {
                zeroCount++;
            }

            mini = min(zeroCount, mini);
        }

        return mini;
    }
};