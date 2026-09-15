class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nextmin(n,n);
        vector<int> prevmin(n,-1);
        stack<int> mini;
        for(int i=0;i<n;i++)
        {
            while(!mini.empty() && heights[mini.top()]>= heights[i])
            {
                mini.pop();
            }
            if(!mini.empty())
            {
                prevmin[i] = mini.top();
            }
            mini.push(i);
        }

        while(!mini.empty()){
            mini.pop();
        }

        for(int i=n-1;i>=0;i--)
        {
            while(!mini.empty() && heights[mini.top()] > heights[i])
            {
                mini.pop();
            }
            if(!mini.empty())
            {
                nextmin[i] = mini.top();
            }
            mini.push(i);
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans = max(ans,((heights[i])*(nextmin[i]-prevmin[i]-1)));
            // cout<<"for"<<heights[i]<<"nextmin is "<<nextmin[i]<<"and prevmin is"<<prevmin[i]<<endl;
        }
        return ans;
    }
};