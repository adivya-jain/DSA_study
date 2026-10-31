#include <bits/stdc++.h>
using namespace std;

long long zeros(long long n) {
    long long ans = 0;

    while (n) {
        n /= 5;
        ans += n;
    }

    return ans;
}

int main() {
    long long m;
    cin >> m;

    long long lo = 0, hi = 5 * m;

    while (lo < hi) {
        long long mid = (lo + hi) / 2;

        if (zeros(mid) >= m) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    if (zeros(lo) != m) {
        cout << 0 << '\n';
    } else {
        cout << 5 << '\n';

        for (long long i = lo; i < lo + 5; i++) {
            cout << i << " ";
        }

        cout << '\n';
    }

    return 0;
}