#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str = "1001010100101001000101111010110111110100101010101001101010010110111101001010110101110010101101001011";
    vector<int> prefix(str.length()+1);
    prefix[0] = 0;

    for(int i=1;i<str.length();i++)
    {
        if(str[i-1] == '1')
        {
            prefix[i] = prefix[i-1] + 1;
        }else{
            prefix[i] = prefix[i-1] - 1;
        }
    }
    int maxi =0;
    stack<pair<int,int>> st;
    for(int i=0;i<prefix.size();i++)
    {
        
    }

}