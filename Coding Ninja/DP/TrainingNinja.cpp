int solve(int n,int j,vector<vector<int>>&matrix,vector<vector<long long>>&T)
    {
        if(n<0) return 0;

        if(T[n][j]!=-1) return T[n][j];
        T[n][j] = max(solve(n-1,(j+1)%3,matrix,T),solve(n-1,(j+2)%3,matrix,T))+matrix[n][j%3];
        return T[n][j];
    }

int ninjaTraining(int n, vector<vector<int>> &matrix)
{
        vector<vector<long long>> T(n+1,vector<long long>(3,-1));
        return max(solve(n-1,0,matrix,T),max(solve(n-1,1,matrix,T),solve(n-1,2,matrix,T)));

}


