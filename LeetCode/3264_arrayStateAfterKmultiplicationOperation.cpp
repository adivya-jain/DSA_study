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

//more optimized 

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(make_pair(nums[i],i));
        }
        while(k--)
        {
            pair<int,int> small = pq.top();
            pq.pop();
            nums[small.second] = nums[small.second] * multiplier;
            pq.push({nums[small.second],small.second});
        }

        return nums;
    }
};