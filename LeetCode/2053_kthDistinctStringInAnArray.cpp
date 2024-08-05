class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for (auto v : arr) {
            mp[v]++;
        }
        vector<string> ans;
        for (auto& v : arr) {
            if (mp[v] == 1) {
                k--;
                if (k == 0) {
                    return v;
                }
            }
        }
        return "";
    }
};