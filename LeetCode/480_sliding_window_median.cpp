class Solution {
public:

    using P = pair<int, int>;

    using MaxHeap = priority_queue<P>;

    using MinHeap = priority_queue<P, vector<P>, greater<P>>;


    void removeGarbage(MaxHeap& low, MinHeap& high,
                       int& l, int& r, int index) {

        while (!low.empty() && low.top().second <= index) {
            low.pop();
            l--;
        }

        while (!high.empty() && high.top().second <= index) {
            high.pop();
            r--;
        }
    }


    void balance(MaxHeap& low, MinHeap& high,
                 int& l, int& r,
                 vector<bool>& Flag) {

        // valid elements in high > valid elements in low
        while (high.size() - r > low.size() - l) {

            P x = high.top();
            high.pop();

            low.push(x);
            Flag[x.second] = true;
        }

        // low can have at most 1 extra element
        while (low.size() - l > high.size() - r + 1) {

            P x = low.top();
            low.pop();

            high.push(x);
            Flag[x.second] = false;
        }
    }


    void add(MaxHeap& low, MinHeap& high,
             int num, int index,
             int& l, int& r,
             vector<bool>& Flag) {

        if (low.empty() || num <= low.top().first) {
            low.push({num, index});
            Flag[index] = true;
        }
        else {
            high.push({num, index});
            Flag[index] = false;
        }

        balance(low, high, l, r, Flag);
    }


    void remove(MaxHeap& low, MinHeap& high,
                int index, int& l, int& r,
                vector<bool>& Flag) {

        if (Flag[index])
            l++;
        else
            r++;

        removeGarbage(low, high, l, r, index);
    }


    double getMedian(MaxHeap& low, MinHeap& high, int k) {

        if (k % 2)
            return low.top().first;

        return ((double)low.top().first +
                high.top().first) / 2.0;
    }


    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        MaxHeap low;
        MinHeap high;

        vector<bool> Flag(nums.size());

        int l = 0;
        int r = 0;

        vector<double> ans;

        for (int i = 0; i < nums.size(); i++) {

            // Add new element
            add(low, high, nums[i], i, l, r, Flag);

            // Remove element outside window
            if (i >= k) {
                remove(low, high, i - k, l, r, Flag);
            }

            // Rebalance after removal
            balance(low, high, l, r, Flag);

            // Remove garbage at tops
            removeGarbage(low, high, l, r, i - k);

            // Window is ready
            if (i >= k - 1) {
                ans.push_back(getMedian(low, high, k));
            }
        }

        return ans;
    }
};