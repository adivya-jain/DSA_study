class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while(numBottles>=numExchange)
        {
            int numBottlesE = numBottles % numExchange;
            numBottles = numBottles / numExchange;
            ans = ans + numBottles;
            numBottles = numBottles + numBottlesE;
        }
        return ans;
    }
};