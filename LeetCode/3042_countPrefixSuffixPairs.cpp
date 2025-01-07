class Solution {
bool prefix(string str1, string str2)
{   
    for(int i=0;i<str1.length();i++)
    {
        if(str1[i]!=str2[i]) return false;
    }
    return true;

}
    bool suffix(string str1,string str2)
    {
        for(int i=0;i<str1.size();i++)
        {
            if(str1[str1.length()-i-1]!=str2[str2.size()-1-i]) return false;
        }
        return true;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(words[j].length() < words[i].length())
                {
                    continue;
                }
                else if(prefix(words[i],words[j]))
                {
                    if(suffix(words[i],words[j]))
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};