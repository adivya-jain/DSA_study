#include<iostream>
#include<map>
using namespace std;

int atmostKsubstring(string s,int k)
{
    int left = 0;
    map<char,int> freq;
    int cnt=0;

    for(int right=0;right<s.length();right++)
    {
        freq[s[right]]++;

        while(freq.size() > k)
        {
            freq[s[left]]--;

            if(freq[s[left]] == 0)
                freq.erase(s[left]);

            left++;
        }

        cnt += right - left + 1;
    }

    return cnt;

}


int main()
{
    string s = "pqpqs";
    int k=2;

    cout << atmostKsubstring(s,k) - atmostKsubstring(s,k-1);

    return 0;
}

