class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        priority_queue<int> maxheap(nums.begin(), nums.end());

        while(k>0)
        {
            int add = maxheap.top();
            maxheap.pop();

            ans+=add;
            maxheap.push(ceil((double)add/3));
            
            k--;
        }
        return ans;
    }
};