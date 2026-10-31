#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n), pref(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }

    deque<int> dq;
    __int128 best = -((__int128)1 << 126);
    int ans = 0;

    for (int r = 1; r <= n; r++) {
        int idx = r - 1;

        while (!dq.empty() && pref[dq.back()] > pref[idx])
            dq.pop_back();

        dq.push_back(idx);

        while (!dq.empty() && dq.front() < r - k)
            dq.pop_front();

        __int128 sum = (__int128)pref[r] - pref[dq.front()];
        int len = r - dq.front();

        if (sum > best) {
            best = sum;
            ans = len;
        } else if (sum == best) {
            ans = max(ans, len);
        }
    }

    cout << ans << '\n';
    return 0;
}