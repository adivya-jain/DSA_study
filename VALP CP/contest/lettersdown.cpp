#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin >> test;

    while (test--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int i = 0, j = n - 1;
        int ans = 0;

        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            }
            else if (s[i] > s[j]) {
                char x = s[i];

                for (int k = 0; k < n; k++) {
                    if (s[k] == x)
                        s[k]--;
                }

                ans++;
            }
            else {
                char x = s[j];

                for (int k = 0; k < n; k++) {
                    if (s[k] == x)
                        s[k]--;
                }

                ans++;
            }
        }

        cout << ans << "\n";
    }
}