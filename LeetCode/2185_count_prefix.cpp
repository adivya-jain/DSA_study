class Solution {
    bool prefix(string temp, string pref)
    {
        for(int i=0;i<pref.length();i++)
        {
            if(pref[i]!= temp[i]) return false;
        }
        return true;
    }
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for(int i=0;i<words.size();i++)
        {
            string temp = words[i];
            if(prefix(temp,pref))
            {
                count++;
            }
        }
        return count;
    }
};