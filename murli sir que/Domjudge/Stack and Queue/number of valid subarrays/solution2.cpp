#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    stack<int> st;
    long long total = 0;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() > arr[i])
        {
            st.pop();
        }

        st.push(arr[i]);

        total += st.size();
    }

    cout << total << endl;

    return 0;
}