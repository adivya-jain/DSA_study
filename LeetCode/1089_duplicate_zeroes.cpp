class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        // without Auxially space
        int zeros = 0;
        int nonzero = 0;
        int k = 0;
        int n = arr.size();
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0) {
                nonzero++;
            } else {
                zeros += 2;
            }

            if (zeros + nonzero >= n) {
                k = i;
                break;
            }
        }
        int right = n - 1;
        if (zeros + nonzero > n) {
                arr[right] = 0;
                right--;
                k--;
        }
        cout << k;
        while (k >= 0) {
            if (arr[k] != 0) {
                arr[right] = arr[k];
            }
          else {
                arr[right] = 0;
                right--;
                arr[right] = 0;
            }

            right--;
            k--;
        }
    }
};