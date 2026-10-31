 Frog Jump
 //top down

 #include <bits/stdc++.h> 
   int solve(int n,vector<int>& heights,vector<int>&dp)
    {
        if(n==0) return 0;
        if(n==1) return abs(heights[1]-heights[0]);

        if(dp[n]!=-1) return dp[n];


        int prev = solve(n-1,heights,dp) + abs(heights[n]-heights[n-1]);
        int prev2 =solve(n-2,heights,dp) + abs(heights[n]-heights[n-2]); 
        dp[n] = min(prev,prev2);

        return dp[n];

    }

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    return solve(n-1,heights,dp);
    
}


//bottom up 
   int solve(int n,vector<int>& heights)
    {
        vector<int> dp(n+1,0); //initalization

        //base case
        dp[0] = 0;
        dp[1] = abs(heights[1]-heights[0]);

    //tabulation
        for(int i=2;i<=n;i++)
        {
            dp[i] = min(
                abs(heights[i]-heights[i-1]) +dp[i-1],
                abs(heights[i]-heights[i-2]) +dp[i-2]
                );
        }

        return dp[n-1];

    }