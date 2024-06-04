class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freqMap;
        int res = 0;
        int oddCount = 0;

        for (char ch : s) {
            freqMap[ch]++;
            int curFreq = freqMap[ch];
            if (curFreq % 2 == 0) {
                res += 2;
                oddCount--;
            } else {
                oddCount++;
            }
        }

        if (oddCount > 0) {
            res++;
        }

        return res;
    }
};