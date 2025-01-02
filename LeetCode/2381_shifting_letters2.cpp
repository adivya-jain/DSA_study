class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> difference(s.length());
        for (auto que : shifts) {
            difference[que[0]] += que[2] == 1 ? 1 : -1;
            if(que[1]+1 < s.length()) difference[que[1] + 1] += que[2] == 1 ? -1 : 1;
        }
        int numberOfShifts=0;
        for (int i = 0; i < s.length(); i++) {
            numberOfShifts = (numberOfShifts + difference[i]) % 26;
            if (numberOfShifts < 0)
                numberOfShifts += 26;
            s[i] = 'a' + (s[i] - 'a' + numberOfShifts) % 26;
        }
        return s;
    }
};