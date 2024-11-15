class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        vector<int> window(k, -1);
        for (int i = 0; i < k; i++) {
            window[i] = nums[i];
            // if(ans)
        }
        for (int i = 0; i < window.size() - 1; i++) {
            if ((window[i] + 1) != window[i + 1]) {
                ans.push_back(-1);
                break;
            }
        }
        if (ans.size() == 0)
            ans.push_back(window[window.size() - 1]);
        for (int i = k; i < nums.size(); i++) {
            int currsize = ans.size();
            window.erase(window.begin());
            window.push_back(nums[i]);
            for (int i = 0; i < window.size() - 1; i++) {
                if ((window[i] + 1) != window[i + 1]) {
                    ans.push_back(-1);
                    break;
                }
            }
            if (ans.size() == currsize) {
                ans.push_back(window[window.size() - 1]);
            }
        }
        return ans;
    }
};