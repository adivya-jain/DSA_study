
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long h, p;
        cin >> h >> p;

        int k = 0;

        if (p > 1) {
            k = 64 - __builtin_clzll(p - 1);
        }

        k = min((long long)k, h);

        long long remaining = (1LL << h) - (1LL << k);
        long long moments = (remaining + p - 1) / p;

        cout << k + moments << '\n';
    }

    return 0;
}
