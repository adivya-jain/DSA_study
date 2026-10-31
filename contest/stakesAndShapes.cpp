#include<bits/stdc++.h>
using namespace std;


void solve()
{
    int r, s, p;
    cin >> r >> s >> p;

    int n = r + s + p;
    int mx = max(max(r,s),p);
    char ch;
    if(mx == r)
        ch='P';
    else if(mx == s)
        ch='R';
    else ch='S';

    for(int i = 0; i < n; i++)
    {
        cout<<ch;
    }
    cout<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
int t;
cin>>t;
while(t--)
    solve();
return 0;
}