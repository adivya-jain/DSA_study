
#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin >> test;

    while (test--) {
        string n;
        cin >> n;

        int x = 0, y = 0;
        int turn = 0;

        for (char c : n) {
            int d = c - '0';

            if (d % 2 == 0) {
                x = x * 10 + d / 2;
                y = y * 10 + d / 2;
            } else {
                if (turn == 0) {
                    x = x * 10 + d / 2 + 1;
                    y = y * 10 + d / 2;
                } else {
                    x = x * 10 + d / 2;
                    y = y * 10 + d / 2 + 1;
                }
                turn = 1 - turn;
            }
        }

        cout << x << " " << y << '\n';
    }

    return 0;
}
