#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    char c = *max_element(s.begin(), s.end());

    int cnt = count(s.begin(), s.end(), c);

    cout << string(cnt, c) << '\n';

    return 0;
}