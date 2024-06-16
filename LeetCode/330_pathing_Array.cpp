// leetcode 330. Patching Array
#include <vector>

class Solution {
    // Helper function to count primes less than or equal to n
    int CountPrimes(int n) {
        if (n < 2) return 0;
        std::vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
        int cnt = 0;
        for (int i = 2; i <= n; ++i) {
            if (prime[i]) {
                ++cnt;
                for (int j = i * 2; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
        return cnt;
    }

public:
    // Main function to find the minimum patches
    int minPatches(std::vector<int>& nums, int n) {
        long long miss = 1;
        int added = 0, i = 0;
        
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss += miss;
                ++added;
            }
        }
        
        return added;
    }
};
