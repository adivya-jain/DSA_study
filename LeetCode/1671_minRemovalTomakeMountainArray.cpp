class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int N=nums.size();
        vector<int> ldslength(N, 1);
        vector<int> lislength(N, 1);

        for (int i = 0; i < N; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    lislength[i] = max(lislength[i], lislength[j] + 1);
                }
            }
        }
        for(int i=N-1;i>=0;i--)
        {
            for(int j = i + 1; j < N; j++)
            {
                if(nums[i]>nums[j])
                {
                    ldslength[i]=max(ldslength[i],ldslength[j]+1);
                }
            }
        }
        int minRemovals = INT_MAX;
        for (int i = 0; i < N; i++) {
            if (lislength[i] > 1 && ldslength[i] > 1) {
                minRemovals =
                    min(minRemovals, N - lislength[i] - ldslength[i] + 1);
            }
        }

        return minRemovals;
    }
};