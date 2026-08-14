class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length())
            return false;
        map<char, int> mp;
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
            mp[t[i]]--;
        }


        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second) return false;
        }

        return true;
    }
};