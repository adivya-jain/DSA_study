// https://codeforces.com/group/xVNEbiFP6v/contest/719428/problem/C

#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--)
    {
        long long x;
        cin>>x;
        if(x==1)
            cout<<3<<'\n';
        else if((x & (x-1))==0) 
            cout<<x+1<<'\n';
        else 
            cout<<(x&-x)<<'\n';  
    }
}