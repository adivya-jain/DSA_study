class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> prefixSum(words.size());
        int sum = 0;
        for (int i = 0; i < words.size(); i++) {
            string str = words[i];
            int len = str.length();
            if (str[0] == 'a' || str[0] == 'e' || str[0] == 'i' || str[0] == 'o' || str[0] == 'u') {
                if (str[len - 1] == 'a' || str[len - 1] == 'e' || str[len - 1] == 'i' || str[len - 1] == 'o' || str[len - 1] == 'u') {
                   sum++;
                }
            }
            prefixSum[i] = sum;
        }
        for (auto que:queries) {
            int u = que[0];
            int v = que[1];
            ans.push_back(prefixSum[v] - (u==0?0:prefixSum[u-1]));
        }
        return ans;
    }
};