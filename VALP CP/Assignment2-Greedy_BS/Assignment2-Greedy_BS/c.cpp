#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s, n;
    cin >> s >> n;

    vector<pair<int, int>> dragon(n);

    for (int i = 0; i < n; i++) {
        cin >> dragon[i].first >> dragon[i].second;
    }

    sort(dragon.begin(), dragon.end());

    for (auto [strength, bonus] : dragon) {
        if (s <= strength) {
            cout << "NO\n";
            return 0;
        }

        s += bonus;
    }

    cout << "YES\n";

    return 0;
}