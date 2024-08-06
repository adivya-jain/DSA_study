class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        vector<int> freq(26, 0);

        for (char c : word) {
            freq[c - 'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int count = 0;
        for (int i = 0; i < 26; i++)
        {
            if(freq[i] == 0) break;
            else if (i < 8) {
                count += freq[i];
            } else if (i < 16) {
                count += 2 * freq[i];
            } else if (i < 24) {
                count += 3 * freq[i];
            } else {
                count += 4 * freq[i];
            }
    }

    return count;
}
}
;
