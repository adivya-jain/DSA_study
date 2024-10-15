class Solution {
public:
    long long minimumSteps(string s) {
        int i = 0;
        int j = s.size()-1;
        long long cnt=0;
        while(i<j)
        {
            if(s[i]=='1'&& s[j]=='0')
            {
                swap(s[i],s[j]);
                cnt+=j-i;
                i++;
                j--;
            }
            if(s[i]=='0') i++;
            if(s[j]=='1') j--;
        }
        return cnt;
    }
};