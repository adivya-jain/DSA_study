// leecode problem no: 826 Most Profit Assigning Work

class Solution {
private:
    int maxValue(vector<int> difficulty, int n) {
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, difficulty[i]);
        }
        return maxi;
    }

public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        int n = difficulty.size();
        int maxdiff = maxValue(difficulty, n);
        vector<int> jobs(maxdiff + 1, 0);

        for (int i = 0; i < n; i++) {
            jobs[difficulty[i]] = max(jobs[difficulty[i]], profit[i]);
        }
        for (int i = 1; i <= maxdiff; i++) {
            jobs[i] = max(jobs[i], jobs[i - 1]);
        }
        int ans = 0;
        for (int w : worker) {
            if (w > maxdiff) {
                ans += jobs[maxdiff];
            } else {
                ans += jobs[w];
            }
        }

        return ans;
    }
};