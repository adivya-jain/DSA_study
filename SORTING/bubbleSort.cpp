class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // bubble sort O(n*(n-1)/2)
        //Total no. of passes: n-1
        //TC O(N2)
        //SC O(1)
        //stable sorting algorithm in-place algorithm.
        for(int i = 0 ; i < nums.size();i++)
        {
            bool swapped = true;
            for(int j = 0 ;j< nums.size()-i-1 ; j++)
            {
                if(nums[j] > nums[j+1])
                {
                    swap(nums[j],nums[j+1]);
                    swapped = true;
                }
            }

            if(swapped == false) break;
        }
        return nums;

    }
};
