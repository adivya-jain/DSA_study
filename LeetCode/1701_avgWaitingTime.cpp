class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int currentTime = 0;
        long long totalwaitTime = 0; // if set to int..cause overflow

        for (auto customer : customers) {

            int arrival = customer[0];
            int time = customer[1]; 

            if (currentTime <
                arrival) // initialize once..further >condition breaks it
            {
                currentTime = arrival; // set to 1
            }
            int waitTime = currentTime + time - arrival;

            // first iteration  1 +2-1 =2
            // second iteration 3+5-2  =6
            // third  iteration 8+3-4  =7
            totalwaitTime += waitTime;

            // 2+6+7=15

            currentTime += time;
            // first it   1+2=3
            // second it  3+5=8
            // third it   8+3=11
        }
        return static_cast<double>(totalwaitTime) /
               customers.size(); //(15)/3=5.00000
    }
};