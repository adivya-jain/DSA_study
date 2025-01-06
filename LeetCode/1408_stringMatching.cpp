class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            string sub = words[i];
            for (int j = 0; j < words.size(); j++) {
                if (i == j)
                    continue;
                if (isSubstringOf(words[i], words[j])) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
    bool isSubstringOf(string& sub, string& main) {
        // Loop through possible starting indices in `main`.
        for (int startIndex = 0; startIndex < main.size(); startIndex++) {
            bool subFits = true;

            // Check if the substring matches from the current start index.
            for (int subIndex = 0; subIndex < sub.size(); subIndex++) {
                if (startIndex + subIndex >= main.size() ||
                    main[startIndex + subIndex] != sub[subIndex]) {
                    subFits = false; // The substring doesn't match.
                    break; // No need to continue further for this start
                           // index.
                }
            }
            if (subFits) {
                return true;  // Found a match, return true.
            }
        }
        return false;

    }
};