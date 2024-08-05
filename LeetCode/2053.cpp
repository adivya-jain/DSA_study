class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
       map<string,int> mp;
       for(int i=0;i<arr.size();i++)
       {
        mp[arr[i]]++;
        if(mp[arr[i]] > 1)
        {
            mp.erase(arr[i]);
        }
       } 
    vector<string> ans;
        for(auto m:mp)
        {
            ans.push_back(m.first);
        }
        if(k>ans.size())
            return "";
        else return ans[k-1];
    }
};