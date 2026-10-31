#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);

    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }

    vector<int> ans(n,n);
    stack<int> st;

    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && nums[st.top()] > nums[i])
        {
            st.pop();
        }
        if(!st.empty())
        {
            ans[i]=st.top();
        }
        st.push(i);
    }

    int a=0;
    for(int i=0;i<n;i++)
    {
      cout<<ans[i];
      a+=ans[i]-i;
    }
    cout<<endl<<a;
    return 0;
}