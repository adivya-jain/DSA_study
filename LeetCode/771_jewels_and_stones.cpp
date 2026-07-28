class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,int> mp;
        for(int i=0;i<stones.length();i++)
        {
            mp[stones[i]]++;
        }
        int ans=0;
        for(int i=0;i<jewels.size();i++)
        {
            ans += mp[jewels[i]];
        }
        return ans;
    }
};