#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string str="";


        for(int i=0;i<n;i++)
        {
            char c;
            cin>>c;
            str+=c;
        }

        int cnt=0;
        if(str[0]=='B')
        {
            cnt++;
        }

        for(int i=1;i<n;i++)
        {
            if(str[i-1]==str[i])
            {
                cnt++;
            }
        }

        cout<<cnt<<'\n';   
    }
}