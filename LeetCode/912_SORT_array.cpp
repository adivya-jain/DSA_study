class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < nums.size(); i++) {
            minHeap.push(nums[i]);
        }
        int i = 0;
        while (!minHeap.empty()) {
            nums[i] = minHeap.top();
            i++;
            minHeap.pop();
        }
        return nums;
    }
};