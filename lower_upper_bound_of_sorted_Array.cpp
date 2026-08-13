#include <bits/stdc++.h>
using namespace std;

// Class containing methods for array operations
class LowerBoundFinder {
public:
    // Function to find lower bound index
    int lowerBound(vector<int> arr, int n, int x) {
        int lower = n;
        int left  = 0;
        int right = n-1;
        while(left <= right)
        {
            int mid = right - ((right - left)/2);

            if(arr[mid] >= x)
            {
                lower = mid;
                right = mid - 1;
            }
            else
            {
                lower = mid + 1;
            }
        }

        return lower;
      
    }
};

int main() {
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = arr.size();  // Size of the array
    int x = 9;           // Target value

    LowerBoundFinder finder;                  // Create object
    int ind = finder.lowerBound(arr, n, x);   // Find lower bound index

    cout << "The lower bound is the index: " << ind << "\n";

    return 0;
}
