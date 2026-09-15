class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();
        vector<int> nextmax(n, n);
        vector<int> prevmax(n, -1);

        vector<int> nextmin(n, n);
        vector<int> prevmin(n, -1);

        stack<int> stmax;
        stack<int> stmin;
        for (int i = 0; i < n; i++) {
            while (!stmin.empty() && nums[stmin.top()] >= nums[i]) {
                stmin.pop();
            }
            if (!stmin.empty()) {
                prevmin[i] = stmin.top();
            }
            stmin.push(i);

            while (!stmax.empty() && nums[stmax.top()] <= nums[i]) {
                stmax.pop();
            }
            if (!stmax.empty()) {
                prevmax[i] = stmax.top();
            }
            stmax.push(i);
        }

        while (!stmin.empty()) {
            stmin.pop();
        }
        while (!stmax.empty()) {
            stmax.pop();
        }

        for (int i = n-1; i >= 0; i--) {
            while (!stmin.empty() && nums[stmin.top()] > nums[i]) {
                stmin.pop();
            }
            if (!stmin.empty()) {
                nextmin[i] = stmin.top();
            }
            stmin.push(i);

            while (!stmax.empty() && nums[stmax.top()] < nums[i]) {
                stmax.pop();
            }
            if (!stmax.empty()) {
                nextmax[i] = stmax.top();
            }
            stmax.push(i);
        }
        long long largest = 0;
        long long smallest = 0;
        for (int i = 0; i < n; i++) {
            largest += 1LL * nums[i] * (nextmax[i] - i) * (i - prevmax[i]);
            smallest += 1LL * nums[i] * (nextmin[i] - i) * (i - prevmin[i]);
        }

        return largest - smallest;
    }
};