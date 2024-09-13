// class Solution {
// public:
//     vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
//         vector<int> ans;
//         for(auto q:queries)
//         {
//             int xorSum = 0;
//             for(int j=q[0];j<=q[1];j++)
//             {
//                  xorSum^=arr[j];
//             }
//             ans.push_back(xorSum);
//         }
//         return ans;
//     }
// };

// OPTIMIZED USING PXREFIX SUM BUT WITH EXTRA SPACE

// class Solution {
// public:
//     vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
//         int n = arr.size();
//         vector<int> prefixSum(n+1,0);
//         for(int i=0;i<n;i++)
//         {
//             prefixSum[i+1] = arr[i]^prefixSum[i];
//         }
//         vector<int>result;
//         for(auto q : queries)
//         {         
//                 result.push_back(prefixSum[q[1]+1]^prefixSum[q[0]]);
//         }
//         return result;
//     }
// };


// OPTIMIZED USING PREFIX SUM WITHOUT EXTRA SPACE

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        for(int i=1;i<n;++i)
        {
            arr[i] ^=arr[i-1];
        }
        vector<int>result;
        for(auto q : queries)
        {         
                result.push_back(q[0]  > 0 ? arr[q[1]]^ arr[q[0]-1]    : arr[q[1]]);
        }
        return result;
    }
};