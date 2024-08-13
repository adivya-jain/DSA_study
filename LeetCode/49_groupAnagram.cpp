class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>> mp;
        for(int i=0;i<strs.size();i++)
        {
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(i);
        }
        vector<vector<string>> ans;

        for(auto it = mp.begin();it!=mp.end();it++)
        {
            vector<string> tempo;
            for(auto pq:it->second)
            {
                tempo.push_back(strs[pq]);
            }

            ans.push_back(tempo);

        }

        return ans;
        
    }
};