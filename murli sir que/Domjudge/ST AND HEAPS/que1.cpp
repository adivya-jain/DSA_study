#include <bits/stdc++.h>
using namespace std;

class Fenwick {
    vector<long long> bit;
    int n;

public:
    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, long long val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    long long query(int idx) {
        long long sum = 0;

        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }

        return sum;
    }
};

int main() {
    int n;
    long long k;

    cin >> n >> k;

    vector<long long> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<long long> vals = nums;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int m = vals.size();

    auto getIndex = [&](long long x) {
        return lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
    };

    auto check = [&](long long x) -> bool {

        Fenwick bit(m);

        long long count = 0;

        for (int j = 0; j < n; j++) {

            long long lowValue = nums[j] + 1;
            long long highValue = nums[j] + x;

            int highIdx =
                upper_bound(vals.begin(), vals.end(), highValue)
                - vals.begin();

            int lowIdx =
                upper_bound(vals.begin(), vals.end(), nums[j])
                - vals.begin();

            long long a = bit.query(highIdx);
            long long b = bit.query(lowIdx);

            count += a - b;

            if (count >= k)
                return true;

            bit.update(getIndex(nums[j]), 1);
        }

        return false;
    };


    long long low = 0;
    long long high = *max_element(nums.begin(), nums.end())
                   - *min_element(nums.begin(), nums.end());

    long long answer = -1;

    while (low <= high) {

        long long mid = low + (high - low) / 2;

        if (check(mid)) {
            answer = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << answer << '\n';

    return 0;
}