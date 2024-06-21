class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int nonGrumpysum = 0;
        int n = customers.size();
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                nonGrumpysum += customers[i];
                customers[i] = 0;
            }
        }

        int grumpysum = 0;
        for (int i = 0; i < minutes; i++) {
            grumpysum += customers[i];
        }
        int maxGrumpysum = grumpysum;
        for (int i = minutes; i < n; ++i) {
            grumpysum += customers[i] - customers[i - minutes];
            maxGrumpysum = max(maxGrumpysum, grumpysum);
        }


        return nonGrumpysum + maxGrumpysum;
    }
};