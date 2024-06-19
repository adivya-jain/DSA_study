class Solution {
    pair<int, int> range(vector<int> bloomDay) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for (int i = 0; i < bloomDay.size(); i++) {
            maxi = max(maxi, bloomDay[i]);
            mini = min(mini, bloomDay[i]);
        }
        return make_pair(mini, maxi);
    }
    bool check(vector<int> bloomDay, int mid,int m ,int k) {
        int count = 0;
        int target = 0;
        for (int i = 0; i < bloomDay.size(); i++) {

            if (bloomDay[i] <= mid) {
                count++;
                if (count == k) {
                    target++;
                    count = 0;
                }
                if (target == m) {
                    return 1;
                }
            } else {
                count = 0;
            }
        }

        return 0;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long)m * k > bloomDay.size())
            return -1;
        pair<int, int> ran = range(bloomDay);
        int start = ran.first;
        int end = ran.second;
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (check(bloomDay, mid, m, k)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};