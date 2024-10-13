class Solution {

public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> hp;
        int currmax = INT_MIN;
        // vector<int> index(n,0);
        // int mini = INT_MAX;
        for(int i=0;i<n;i++)
        {
            hp.push({nums[i][0],i,0});
            currmax = max(currmax,nums[i][0]);
        }
        vector<int> ans = {0,INT_MAX};
        while(true)
        {
            vector<int> smallest = hp.top();
            hp.pop();
            int index = smallest[2];
            
            int row=smallest[1];
            int currmin = smallest[0];
            
            
            if(currmax - currmin < ans[1]-ans[0])
            {
                ans[0] = currmin;
                ans[1] = currmax;
            }
            if(index>= nums[row].size()-1) break;
            index++;
            currmax = max(currmax,nums[row][index]);

            hp.push({nums[row][index],row,index});

        }

        return ans;
        
        return {0,1};
    }
};