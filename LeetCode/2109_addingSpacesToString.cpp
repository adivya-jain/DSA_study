class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        ans.reserve(s.size() + spaces.size());
        int k = 0;
        for (int i = 0; i < s.length(); i++) {
            if (k < spaces.size() && spaces[k] == i) {
                ans +=" ";
                k++;
            }
            ans += s[i];
        }
        return ans;
    }
};