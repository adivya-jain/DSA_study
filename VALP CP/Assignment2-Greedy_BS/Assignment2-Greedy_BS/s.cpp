#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    cin >> a >> b;

    long long s = a + b;
    long long x = 0;

    while ((x + 1) * (x + 2) / 2 <= s) {
        x++;
    }

    vector<long long> d1, d2;

    for (long long i = x; i >= 1; i--) {
        if (i <= a) {
            d1.push_back(i);
            a -= i;
        }
        else {
            d2.push_back(i);
        }
    }

    cout << d1.size() << '\n';

    for (long long v : d1)
        cout << v << " ";
    cout << '\n';

    cout << d2.size() << '\n';

    for (long long v : d2)
        cout << v << " ";
    cout << '\n';

    return 0;
}