#include <iostream>
#include <vector>
using namespace std;
int main()
{
    class Solution
    {
        void solve(vector<int> nums, vector<vector<int>> &ans, vector<int> out, int index)
        {
            // base case
            if (index >= nums.size())
            {
                ans.push_back(out);
                return;
            }

            solve(nums, ans, out, index + 1);

            int element = nums[index];
            out.push_back(element);
            solve(nums, ans, out, index + 1);
        }

    public:
        vector<vector<int>> subsets(vector<int> &nums)
        {

            vector<vector<int>> ans;
            vector<int> out;
            int index = 0;
            solve(nums, ans, out, index);
            return ans;
        }
    };
}