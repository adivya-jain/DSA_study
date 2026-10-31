#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        long long cost=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        int median = arr[(n/2)];
        for(int i=0;i<n;i++)
        {
            cost+=abs(arr[i]-median);
        }
        cout<<cost<<" "<<arr[n-1]-arr[0]<<'\n';

    }
}