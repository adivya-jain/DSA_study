#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        stack<char> st;

        for (char ch : s) {
            if (!st.empty() && ch == 'B') {
                st.pop();
            }
            else {
                st.push(ch);
            }
        }

        cout << st.size() << '\n';
    }

    return 0;
}