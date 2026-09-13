#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*---------------------------------------------------------
  Utility function to print an integer array
---------------------------------------------------------*/
void printIntegerArray(const vector<int>& arr) {
    for (int value : arr) {
        cout << value << " ";
    }
    cout << "\n";
}

/*---------------------------------------------------------
  Utility function to print a floating-point array
---------------------------------------------------------*/
void printDoubleArray(const vector<double>& arr) {
    for (double value : arr) {
        cout << value << " ";
    }
    cout << "\n";
}

/*=========================================================
  1. COUNTING SORT
  Supports positive and negative integers
=========================================================*/
void countingSort(vector<int>& arr) {
    if (arr.empty()) {
        return;
    }

    int minimum = *min_element(arr.begin(), arr.end());
    int maximum = *max_element(arr.begin(), arr.end());

    int range = maximum - minimum + 1;

    vector<int> count(range, 0);
    vector<int> output(arr.size());

    // Count the frequency of each value
    for (int value : arr) {
        count[value - minimum]++;
    }

    // Calculate cumulative frequencies
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Build output from right to left to maintain stability
    for (int i = static_cast<int>(arr.size()) - 1; i >= 0; i--) {
        int value = arr[i];
        int position = count[value - minimum] - 1;

        output[position] = value;
        count[value - minimum]--;
    }

    arr = output;
}

/*=========================================================
  2. RADIX SORT
  Supports non-negative integers
=========================================================*/

/*
  Stable Counting Sort based on one decimal digit.
*/
void countingSortByDigit(vector<int>& arr, long long placeValue) {
    int n = static_cast<int>(arr.size());

    vector<int> output(n);
    vector<int> count(10, 0);

    // Count occurrences of each digit
    for (int value : arr) {
        int digit = static_cast<int>((value / placeValue) % 10);
        count[digit]++;
    }

    // Calculate cumulative frequencies
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build output from right to left to maintain stability
    for (int i = n - 1; i >= 0; i--) {
        int digit =
            static_cast<int>((arr[i] / placeValue) % 10);

        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    arr = output;
}

void radixSort(vector<int>& arr) {
    if (arr.empty()) {
        return;
    }

    // Check whether the input contains negative values
    for (int value : arr) {
        if (value < 0) {
            cerr << "Radix Sort supports only non-negative integers.\n";
            return;
        }
    }

    int maximum = *max_element(arr.begin(), arr.end());

    // Sort by units, tens, hundreds, and so on
    for (long long placeValue = 1;
         maximum / placeValue > 0;
         placeValue *= 10) {

        countingSortByDigit(arr, placeValue);
    }
}

/*=========================================================
  3. BUCKET SORT
  Supports floating-point values in the range [0, 1]
=========================================================*/
void bucketSort(vector<double>& arr) {
    int n = static_cast<int>(arr.size());

    if (n == 0) {
        return;
    }

    // Verify that every value lies within [0, 1]
    for (double value : arr) {
        if (value < 0.0 || value > 1.0) {
            cerr << "Bucket Sort requires values in the "
                 << "range [0, 1].\n";
            return;
        }
    }

    vector<vector<double>> buckets(n);

    // Distribute values into buckets
    for (double value : arr) {
        int bucketIndex;

        // Prevent an out-of-range index when value is exactly 1.0
        if (value == 1.0) {
            bucketIndex = n - 1;
        } else {
            bucketIndex = static_cast<int>(value * n);
        }

        buckets[bucketIndex].push_back(value);
    }

    // Sort the elements inside each bucket
    for (vector<double>& bucket : buckets) {
        sort(bucket.begin(), bucket.end());
    }

    // Merge all buckets into the original array
    int index = 0;

    for (const vector<double>& bucket : buckets) {
        for (double value : bucket) {
            arr[index++] = value;
        }
    }
}

/*=========================================================
  MAIN FUNCTION
=========================================================*/
int main() {
    // Counting Sort example
    vector<int> countingArray = {
        4, -2, 2, 8, 3, 3, 1, -2
    };

    cout << "COUNTING SORT\n";
    cout << "Before sorting: ";
    printIntegerArray(countingArray);

    countingSort(countingArray);

    cout << "After sorting:  ";
    printIntegerArray(countingArray);

    cout << "\n";

    // Radix Sort example
    vector<int> radixArray = {
        170, 45, 75, 90, 802, 24, 2, 66
    };

    cout << "RADIX SORT\n";
    cout << "Before sorting: ";
    printIntegerArray(radixArray);

    radixSort(radixArray);

    cout << "After sorting:  ";
    printIntegerArray(radixArray);

    cout << "\n";

    // Bucket Sort example
    vector<double> bucketArray = {
        0.78, 0.17, 0.39, 0.26, 0.72,
        0.94, 0.21, 0.12, 0.23, 0.68
    };

    cout << "BUCKET SORT\n";
    cout << "Before sorting: ";
    printDoubleArray(bucketArray);

    bucketSort(bucketArray);

    cout << "After sorting:  ";
    printDoubleArray(bucketArray);

    return 0;
}