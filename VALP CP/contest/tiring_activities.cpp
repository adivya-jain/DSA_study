#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, n, m;
    cin >> d >> n >> m;

    vector<int> tiring(n), invigorating(m);

    for (int i = 0; i < n; i++) cin >> tiring[i];
    for (int i = 0; i < m; i++) cin >> invigorating[i];

    int i = 0, j = 0, ans = 0;

    while (i < n || j < m) {
        if (i < n && d >= tiring[i]) {
            d -= tiring[i];
            i++;
            ans++;
        }
        else if (j < m) {
            d += invigorating[j];
            j++;
            ans++;
        }
        else {
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
