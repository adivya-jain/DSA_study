class Solution {
    void solve(vector<string>& ans, int index, string output,
               string digits, vector<string> mappings) {
        if (index >= digits.length()) {
            ans.push_back(output);
            return;
        }
  
        int digit = digits[index] - '0';
        for (int i = 0; i < mappings[digit].length(); i++) {
            output.push_back(mappings[digit][i]);
            solve(ans, index+1, output, digits, mappings);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int index = 0;
        string output;
        if (digits.length() == 0)
            return ans;
        vector<string> mappings = {"",    "",    "abc",  "def", "ghi",
                                   "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(ans, index, output, digits, mappings);

        return ans;
    }
};