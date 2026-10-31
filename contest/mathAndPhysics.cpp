
#include <bits/stdc++.h>
using namespace std;

void mp()
{
    int n;
    cin >> n;

    vector<int> a(n);
    long long sum = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    bool mid = false;

    for(int i = 1; i < n - 1; i++)
    {
        if(a[i] >= 2)
        {
            mid = true;
            break;
        }
    }

    if(mid)
    {
        cout << sum - 1 << '\n';
    }
    else if(a[0] >= 2 || a[n-1] >= 2)
    {
        cout << sum - (n - 1) << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    while(test--)
    {
        mp();
    }

    return 0;
}
