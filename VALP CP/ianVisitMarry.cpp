// https://codeforces.com/group/xVNEbiFP6v/contest/719428/problem/B
#include<iostream>
// #include<numeric>
using namespace std;
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    int te;
    cin >>te;
    while(te--)
    {
        int a,b;
        cin >>a>>b;
        if(gcd(a,b) == 1)
        {
            cout<< 1 << '\n';
            cout<<a<<" "<<b<<'\n';
        }else{
            int x = 1,y=1; 
            while(gcd(x,y)!=1 || gcd(a-x,b-y)!=1)
            {
                x++;
            }

            cout<<2<<'\n';
            cout<<x<<" "<<y<<'\n';
            cout<<a<<" "<<b<<'\n';
        }
    }
}