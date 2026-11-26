#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> a(n);
        unordered_set<long long> s;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }

        bool ans = false;

        if (k == 0) {
            if (s.size() < n)
                ans = true;
        }
        else {
            for (long long x : a) {
                if (s.count(x + k)) {
                    ans = true;
                    break;
                }
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}