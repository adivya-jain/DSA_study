#include<iostream>
using namespace std;
int main()
{
    int n=3;
    bool flag=true;
    for(int i =2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            flag = false;
            break;
        }
    }
    cout<< flag << endl;
    return 0;
}