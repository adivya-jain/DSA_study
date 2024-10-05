class Solution {
public:
    bool matched(vector<int> s1map,vector<int> s2map)
    {
        for(int i=0;i<26;i++)
        {
            if(s1map[i]!=s2map[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n > m) return false;
        vector<int> s1map(26,0);
        vector<int> s2map(26,0);
        
        for(int i=0;i<n;i++)
        {
            s1map[s1[i]-'a']++;
            s2map[s2[i]-'a']++;
        }

        if(matched(s1map,s2map))
        {
            return true;
        }

        for(int i=1;i<m-n;i++)
        {
            s2map[s2[i-1]-'a' ]--;
            s2map[s2[i+n-1]-'a']++;

            if(matched(s1map,s2map))
            {
                return true;
            }
        }


        return false;
    }
};