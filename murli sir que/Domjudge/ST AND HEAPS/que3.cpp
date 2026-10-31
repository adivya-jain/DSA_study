#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;

    queue<int> R, D;
    int n = str.size();

    for (int i = 0; i < n; i++) {
        if (str[i] == 'R')
            R.push(i);
        else
            D.push(i);
    }

    while (!R.empty() && !D.empty()) {
        int r = R.front();
        R.pop();

        int d = D.front();
        D.pop();

        if (r < d)
            R.push(r + n);
        else
            D.push(d + n);
    }

    if (R.empty())
        cout << "Dire";
    else
        cout << "Radiant";

    return 0;
}