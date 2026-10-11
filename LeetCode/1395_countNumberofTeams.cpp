class Solution {
public:
    vector<int> bit1;
    // vector<int> bit2;
    int numTeams(vector<int>& rating) {
        // j is the middle element between i and k
        int n = rating.size();
        vector<int> c1(n, 0);
        vector<int> c2(n, 0);
        vector<int> c3(n, 0);
        vector<int> c4(n, 0);
        bit1.resize(n + 1, 0);

        vector<int> cc = rating; // coordinate compression
        sort(cc.begin(), cc.end());

        auto update = [&](vector<int>& bit, int i, int n) {
            for (; i <= n; i += i & -i) {
                bit[i]++;
            }
        };

        auto query = [&](vector<int>& bit, int i) {
            int cnt = 0;
            for (; i > 0; i -= i & -i) {
                cnt += bit[i];
            }
            return cnt;
        };

        for (int i = 0; i < n; i++) {
            int curr = rating[i]; // consider this as j
            int idx = lower_bound(cc.begin(), cc.end(), curr) - cc.begin() + 1;
            c1[i] = query(bit1, idx - 1); // since no duplicates are present
            update(bit1, idx, n);
        }
        fill(bit1.begin(), bit1.end(), 0);
        for (int i = 0; i < n; i++) {
            int curr = rating[n - 1 - i];
            int idx = lower_bound(cc.begin(), cc.end(), curr) - cc.begin() + 1;
            c2[n - 1 - i] = i - query(bit1, idx);
            update(bit1, idx, n);
        }
        fill(bit1.begin(), bit1.end(), 0);
        for (int i = 0; i < n; i++) {
            int curr = rating[i]; // consider this as j
            int idx = lower_bound(cc.begin(), cc.end(), curr) - cc.begin() + 1;
            c3[i] = i - query(bit1, idx - 1); // since no duplicates are present
            update(bit1, idx, n);
        }
        fill(bit1.begin(), bit1.end(), 0);
        for (int i = 0; i < n; i++) {
            int curr = rating[n - 1 - i];
            int idx = lower_bound(cc.begin(), cc.end(), curr) - cc.begin() + 1;
            c4[n - 1 - i] = query(bit1, idx);
            update(bit1, idx, n);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += c1[i] * c2[i] + c3[i] * c4[i];
        }
        return ans;
    }
};


class Solution {
public:
    int numTeams(vector<int>& rating) {
        int count = 0;
        int n = rating.size();
        for (int mid = 1; mid < n - 1; mid++) {
            int leftSmaller = 0;
            int rightGreater = 0;
            for (int i = mid; i >= 0; i--) {
                if (rating[i] < rating[mid]) {
                    leftSmaller++;
                }
            }
            for (int i = mid + 1; i < n; i++) {
                if (rating[i] > rating[mid]) {
                    rightGreater++;
                }
            }

            count += leftSmaller * rightGreater;

            int leftGreater = mid - leftSmaller;
            int rightSmaller = n - mid - 1 - rightGreater;

            count += leftGreater * rightSmaller;
        }
        return count;
    }
};