#include<bits/stdc++.h>
using namespace std;

// #include "BinaryPower.cpp"



vector<vector<int>> MM(vector<vector<int>> A, vector<vector<int>> B)
{
    int r1 = A.size();
    int c1 = A[0].size();

    int r2 = B.size();
    int c2 = B[0].size();

    // Matrix multiplication possible only if c1 == r2
    if(c1 != r2)
        return {};

    vector<vector<int>> result(r1, vector<int>(c2, 0));

    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            for(int k = 0; k < c1; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}



vector<vector<int>> findpow(vector<vector<int>> nums,int n)
{
    if(n<1) return {{1,0,0},{0,1,0},{0,0,1}};

    if(n%2)
    {
        return MM(nums,(findpow(MM(nums,nums),n/2)));
    }else{
          
        return findpow(MM(nums,nums),n/2);
    
    }

}



int main()
{
    // MAtrix multiplication


    vector<vector<int>> nums={
        {2,0,-3},
        {1,0,0},
        {0,1,0},
    };


    int n=10;
    // cout << "Enter the term whose value you want (int)";
    // cin >> n;

    if(n <= 2) return n;

    vector<vector<int>> finalmatrix = findpow(nums,n-2);
    vector<vector<int>> standard = {{2},{1},{0}}; 


    vector<vector<int>> ans = MM(finalmatrix,standard);

     cout << "F(" << n << ") = " << ans[0][0] << endl;

    cout<<"Thank You!";

}