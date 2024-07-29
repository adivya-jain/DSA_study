class Solution {
public:
    int numTeams(vector<int>& rating) {
        int count = 0;
        int n = rating.size();
        for (int mid = 1; mid < n - 1; mid++) {
            int leftSmaller = 0;
            int rightGreater = 0;
            for (int i = mid; i >= 0; i--) {
                if (rating[i] < rating[mid]) {
                    leftSmaller++;
                }
            }
            for (int i = mid + 1; i < n; i++) {
                if (rating[i] > rating[mid]) {
                    rightGreater++;
                }
            }

            count += leftSmaller * rightGreater;

            int leftGreater = mid - leftSmaller;
            int rightSmaller = n - mid - 1 - rightGreater;

            count += leftGreater * rightSmaller;
        }
        return count;
    }
};