#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        long long total = 0, oneCount = 0;
        for(int i = 0; i < n; i++)
        {
            long long a;
            cin>>a;
            total += a;
            if(a == 1) oneCount++;
        }
        if(n > 1 && total - n >= oneCount) cout<<"YES\n";
        else cout<<"NO\n";
    }
}