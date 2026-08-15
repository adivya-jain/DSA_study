class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        map<char, int> mp;

            auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second < b.second;
            };

        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>
            pq(cmp);
        for (auto it = mp.begin(); it != mp.end(); it++) {
                pq.push(pair(it->first,it->second));
        }
        int i = 0;
        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            while (p.second) {
                ans += p.first;
                p.second -= 1;
                i++;
            }
        }
        return ans;
    }
};