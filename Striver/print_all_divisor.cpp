#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n = 36;
    vector<int> arr={1};
    for(int i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            arr.push_back(i);
        }
    }
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<"   ";
    }
    return 0;
}