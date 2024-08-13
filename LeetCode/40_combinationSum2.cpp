class Solution {

void solve(vector<vector<int>>&ans,vector<int> out,vector<int>& candidates,int target,int index)
{
    if(target == 0)
    {
        ans.push_back(out);
        return;
    }

    for(int i=index;i<candidates.size() && candidates[i] <=target;i++)
    {
        if(i==index || candidates[i]!=candidates[i-1])
        {
            out.push_back(candidates[i]);
            solve(ans,out,candidates,target-candidates[i],i+1);
            out.pop_back();
        }
    }
}
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> out;
sort(candidates.begin(),candidates.end());
        solve(ans,out,candidates,target,0);
        return ans;
    }
};