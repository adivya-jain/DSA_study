class Solution {
    int solve(int currA,int clip,int n)
    {
        if(currA==n) return 0;
        if(currA > n) return 10000;

        int copyAll = 1+1+solve(currA+currA,currA,n);
        int paste = 1 + solve(currA+clip,clip,n);
        return min(copyAll,paste);
    }
public:
    int minSteps(int n) {
        if(n==1) return 0;
        return 1 + solve(1,1,n);
    
    }
};