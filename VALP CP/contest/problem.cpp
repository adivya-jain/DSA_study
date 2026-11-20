#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin >> test;

    while (test--) {
        int a, b, c;
        cin >> a >> b >> c;

        int sum = a + b + c;

        if (sum % 3 != 0) {
            cout << "NO\n";
            continue;
        }

        sort(array<int, 3>{a, b, c}.begin(),
             array<int, 3>{a, b, c}.end());

        int x = sum / 3;

        if (a == x - 1 && b == x && c == x + 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}