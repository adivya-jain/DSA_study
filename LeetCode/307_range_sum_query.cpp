class NumArray {
public:
    vector<int> nums;
    vector<int> ST;
    int n;

    NumArray(vector<int>& nums) {
        this->nums = nums;

        int originalSize = nums.size();

        n = 1;
        while (n < originalSize)
            n *= 2;

        ST.resize(2 * n - 1, 0);

        // Leaves
        for (int i = 0; i < originalSize; i++) {
            ST[n - 1 + i] = nums[i];
        }

        // Internal nodes
        for (int i = n - 2; i >= 0; i--) {
            ST[i] = ST[2 * i + 1] + ST[2 * i + 2];
        }
    }

    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;

        // Move to leaf
        index = n - 1 + index;
        ST[index] = val;

        // Update ancestors
        while (index > 0) {
            index = (index - 1) / 2;
            ST[index] += diff;
        }
    }

    int RecurSum(int ss, int se, int l, int r, int p) {
        // Completely outside
        if (se < l || ss > r)
            return 0;

        // Completely inside
        if (l <= ss && se <= r)
            return ST[p];

        int mid = (ss + se) / 2;

        return RecurSum(ss, mid, l, r, 2 * p + 1)
             + RecurSum(mid + 1, se, l, r, 2 * p + 2);
    }

    int sumRange(int left, int right) {
        return RecurSum(0, n - 1, left, right, 0);
    }
};