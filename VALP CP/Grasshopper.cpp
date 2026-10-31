// https://codeforces.com/group/xVNEbiFP6v/contest/719428/problem/A

#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, k;
        cin >> x >> k;

        if (x % k == 0)
        {
            cout << 2 << endl;
            cout << x - 1 <<" "<<1<< endl;
        }
        else
            cout << 1 << endl << x <<endl;
    }
}