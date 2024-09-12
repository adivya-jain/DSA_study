class Solution {
    bool consistent(string word,vector<bool>& present)
    {
        for(auto chart:word)
        {
            if(!present[chart-'a'])
                return false;
        }
        return true;
    }
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> present(26,false);
        for(int i=0;i<allowed.length();i++)
        {
            present[allowed[i]-'a']=true;
        }

        int count=0;
        for(auto word:words)
        {
            if(consistent(word,present))
                count++;
        }
        return count;
    }
};