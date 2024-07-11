class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        for(auto &log: logs){
            if(log=="../")
                ans--;
            else if(log!="./")
                ans++;
            ans=max(ans,0);
        }
        return ans;
    }
};