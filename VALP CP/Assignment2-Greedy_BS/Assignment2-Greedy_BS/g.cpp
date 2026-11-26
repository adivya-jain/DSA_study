#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    string ans;
    char mx = 'a';

    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] >= mx) {
            ans.push_back(s[i]);
            mx = s[i];
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans << '\n';

    return 0;
}