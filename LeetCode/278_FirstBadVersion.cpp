// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1;
        int end = n;
        int mid = (start + (end - start) / 2);
        int ans;
        while (start <= end) {
           
            if (isBadVersion(mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }

            mid = start + (end - start) / 2;
        }


        return ans;
    }
};