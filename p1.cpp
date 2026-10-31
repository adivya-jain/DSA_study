#include<iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    int cnt = 1;
    while(t--) {
        int a;
        cin >> a;
        cout << cnt << "th output is " << a << endl;
        cnt++;
    }

    return 0;
}
