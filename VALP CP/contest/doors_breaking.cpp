
#include <bits/stdc++.h>
using namespace std;

int main() {
    int doors, damage, repair;
    cin >> doors >> damage >> repair;

    vector<int> durability(doors);

    for (int i = 0; i < doors; i++) {
        cin >> durability[i];
    }

    if (damage > repair) {
        cout << doors << endl;
    }
    else {
        int breakable = 0;

        for (int i = 0; i < doors; i++) {
            if (durability[i] <= damage) {
                breakable++;
            }
        }

        cout << (breakable + 1) / 2 << endl;
    }

    return 0;
}
