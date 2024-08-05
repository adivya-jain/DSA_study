// class Solution {
//     int const mod = 1000000007;
//     void solve(vector<int> nums,int prev,vector<int> &ans,int index,int sum)
//     {
//         if(index >= nums.size())
//         {
//             ans.push_back(sum);
//             return;
//         }

//         if(prev==0)
//         {
//             solve(nums,1,ans,index+1,sum+nums[index]);
//             solve(nums,0,ans,index+1,sum);
//         }
//         if(prev ==1 )
//         {
//             solve(nums,1,ans,index+1,sum+nums[index]);
//             solve(nums,0,ans,nums.size(),sum);
//         }

//     }
// public:
//     int rangeSum(vector<int>& nums, int n, int left, int right) {
//         vector<int> ans;
//         long long sum=0;
//         solve(nums,0,ans,0,sum);
//         sort(ans.begin(),ans.end());
//         for(int i=left;i<=right;i++)
//         {
//             sum+=ans[i];
//         }
//         return sum%mod;
//     }
// };
OPTIMIZED
class Solution {
public:
    struct compare {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return a.first > b.first;
        }
    };
    long long const MOD = 1000000007;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(make_pair(nums[i], i));
        }
        long long sum = 0;
        for (int i = 1; i <= right; i++) {
            pair<int, int> temp = pq.top();
            pq.pop();
            if (i >= left) {
                sum = (sum  + temp.first) % MOD;
            }
            if (temp.second + 1 < n) {
                temp.second = temp.second + 1;
                pq.push(make_pair(temp.first + nums[temp.second], temp.second));
            }
        }
        return sum ;
    }
};