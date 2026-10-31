
#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin >> test;

    while (test--) {
        int n, k;
        long long q;
        cin >> n >> k >> q;

        long long ans = 0;
        int len = 0;

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;

            if (x <= q) {
                len++;
            } else {
                if (len >= k) {
                    ans += 1LL * (len - k + 1) * (len - k + 2) / 2;
                }
                len = 0;
            }
        }

        if (len >= k) {
            ans += 1LL * (len - k + 1) * (len - k + 2) / 2;
        }

        cout << ans << '\n';
    }

    return 0;
}
