class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> mp;
        unordered_set<int> st;
        
        for (int i = 1; i <= n; i++) {
            st.insert(i);
        }
        for (int i = 0; i < trust.size(); i++) {
            mp[trust[i][1]]++;
            st.erase(trust[i][0]);
        }

        for(int s:st)
        {
            if(mp[s] == n-1) return s;
        }

        return -1;
        
    }
};