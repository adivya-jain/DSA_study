class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buyPrice = prices[0];
        for(int i=1;i<prices.size();i++)
        {
            if(buyPrice > prices[i])
                buyPrice = prices[i];
            profit = max(profit,prices[i] - buyPrice);
        }
        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //optimal
        int maxi = 0;
        int n = prices.size();
        vector<int> maxiarr(n,0);
        maxiarr[n-1] = prices[n-1];
        for (int i = n - 2 ; i >=0 ; i--) {
            maxiarr[i] = max(maxiarr[i+1],prices[i]);
            maxi = max(maxi,maxiarr[i] - prices[i]);
        }

        return maxi;
    }
};