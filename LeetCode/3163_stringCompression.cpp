class Solution {
public:
    string compressedString(string word) {
        string ans;
        int index=0;
        while(index<word.length())
        {
            int cnt=0;
            char curr = word[index];
            while(word[index]==curr && cnt<9 && index<word.length())
            {
                cnt++;
                index++;
            }
            ans+=to_string(cnt);
            ans+=curr;
        }
        return ans;
    }
};