class Solution {
public:
    int cnt = 0;

    int merge(vector<int>& nums, int low, int mid, int high) {

        vector<int> temp;

        // 1. Count reverse pairs
        int right = mid + 1;

        for (int i = low; i <= mid; i++) {

            while (right <= high &&
                   nums[i] > 2LL * nums[right]) {
                right++;
            }

            cnt += right - (mid + 1);
        }

        // 2. Normal merge
        int left = low;
        right = mid + 1;

        while (left <= mid && right <= high) {

            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            }
            else {
                temp.push_back(nums[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left++]);
        }

        while (right <= high) {
            temp.push_back(nums[right++]);
        }

        // 3. Copy sorted elements back
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }

        return cnt;
    }

    void mergesort(vector<int>& nums, int low, int high) {

        if (low >= high)
            return;

        int mid = low + (high - low) / 2;

        mergesort(nums, low, mid);
        mergesort(nums, mid + 1, high);

        merge(nums, low, mid, high);
    }

    int reversePairs(vector<int>& nums) {

        cnt = 0;

        if (nums.empty())
            return 0;

        mergesort(nums, 0, nums.size() - 1);

        return cnt;
    }
};