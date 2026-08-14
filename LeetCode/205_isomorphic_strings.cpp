class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int lenS = s.length();
        int lenT = t.length();
        if(lenS != lenT) return false;
        unordered_map<char,char> mp;
        for(int i=0;i<lenS;i++)
        {
            
            if(mp.find(s[i]) == mp.end())
            {
                for(auto it=mp.begin();it!=mp.end();it++)
                {
                    if(it->second == t[i])
                    {
                        return false;
                    }
                }
                mp[s[i]] = t[i];
            }else{
                if(mp[s[i]] != t[i]) return false;
            }
        }

        return true;
    }
};