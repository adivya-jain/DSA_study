class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int chillar = 0,tenchillar = 0;
        for (int x:bills) {
            if (x == 5)
                chillar++;
            else if (x == 10) {
                if (chillar > 0) {
                    chillar--;
                    tenchillar++;
                } else
                    return false;
            } else {
                if (chillar > 0 && tenchillar > 0) {
                    chillar--;
                    tenchillar--;
                } else if (chillar > 2) {
                    chillar -= 3;
                } else
                    return false;
            }
        }
        return true;
    }
};