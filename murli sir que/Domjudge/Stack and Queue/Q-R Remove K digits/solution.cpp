#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin >> str;

    int k;
    cin >> k;

    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        while (!st.empty() && k > 0 && str[i] < st.top())
        {
            st.pop();
            k--;
        }
        st.push(str[i]);
    }
    string ans;
    while (k > 0 && !st.empty())
    {
        st.pop();
        k--;
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    int pos = 0;
    while (pos < ans.size() && ans[pos] == '0')
    {
        pos++;
    }
    if (pos == ans.size())
    {
        cout << "0";
        return 0;
    }

    cout << ans.substr(pos);
    return 0;
}