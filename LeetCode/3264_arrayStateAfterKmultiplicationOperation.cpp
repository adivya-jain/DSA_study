class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<unsigned int,unsigned int>,vector<pair<unsigned int,unsigned int>>,greater<pair<unsigned int,unsigned int>>> minHeap;

        for(int i=0;i<nums.size();i++)
        {
            minHeap.push({nums[i],i});
        }
        while(k)
        {
            pair<unsigned int,unsigned int> top = minHeap.top();
            minHeap.pop();
            top.first*=multiplier;
            minHeap.push(top);
            k--;
        }

        while(!minHeap.empty())
        {
            pair<unsigned int,unsigned int> top = minHeap.top();
            minHeap.pop();
            nums[top.second] = top.first;
        }
        return nums;
    }
};