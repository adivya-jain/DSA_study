#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        unordered_map<char,int> mp;
        int n,m;
        cin>>n>>m;

        string p;
        string q;
        cin>>p>>q;
        for(int i=0;i<n;i++)
        {
            mp[p[i]]++;
        }

        for(int i=0;i<m;i++)
        {
            mp[q[i]]--;
            if(mp[q[i]]==0)
            {
                mp.erase(q[i]);
            }
        }

        if(mp.size()!=3) cout<<"NO"<<'\n';
        else if(mp.count('s') && mp.count('i') && mp.count('x') &&
        mp['s'] == 1 && mp['i'] == 1 && mp['x'] == 1)
        {
            cout<<"YES"<<'\n';
        }else{
            cout<<"NO"<<'\n';
        }
    }

}