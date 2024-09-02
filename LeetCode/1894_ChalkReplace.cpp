// class Solution {
// public:
//     int chalkReplacer(vector<int>& chalk, int k) {
//         // Find the sum of all elements.
//         int sum = 0;
//         for (int i = 0; i < chalk.size(); i++) {
//             sum += chalk[i];
//             if (sum > k) {
//                 break;
//             }
//         }
//         // Find modulo of k with sum.
//         k = k % sum;
//         for (int i = 0; i < chalk.size(); i++) {
//             if (k < chalk[i]) {
//                 return i;
//             }
//             k = k - chalk[i];
//         }
//         return 0;
//     }
// };
OPTIMIZED CODE
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // Find the sum of all elements.
        int n=chalk.size();
        vector<long> prefixSum(n);
        prefixSum[0] = chalk[0];
        for (int i = 1; i < chalk.size(); i++) {
            prefixSum[i] = prefixSum[i - 1] + chalk[i];
        }
        // Find modulo of k with sum.
        long sum = prefixSum[n-1];
        int rem = k % sum;
        return BinarySearch(prefixSum, rem);
    }
    int BinarySearch(vector<long>& prefixSum, int rem) {
        int low = 0;
        int high = prefixSum.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if(prefixSum[mid]<=rem)
                low=mid+1;
            else high = mid;
        }
        return high;
    }
};