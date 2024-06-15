// leetcode 502. IPO
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        // Min-heap for projects sorted by capital
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minCapitalHeap;
        
        // Max-heap for feasible projects based on profit
        priority_queue<int> maxProfitHeap;
        
        for (int i = 0; i < n; i++) {
            minCapitalHeap.push({capital[i], profits[i]});
        }

        int currentCapital = w;

        for (int i = 0; i < k; i++) {
            // Move all feasible projects to the maxProfitHeap
            while (!minCapitalHeap.empty() && minCapitalHeap.top().first <= currentCapital) {
                maxProfitHeap.push(minCapitalHeap.top().second);
                minCapitalHeap.pop();
            }

            // If no projects are feasible, break the loop
            if (maxProfitHeap.empty()) {
                break;
            }

            // Select the project with the maximum profit
            currentCapital += maxProfitHeap.top();
            maxProfitHeap.pop();
        }

        return currentCapital;
    }
};