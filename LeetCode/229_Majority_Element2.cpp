class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        map<int,int>mp;
vector<int> ans;
int size= nums.size();
        for(int i=0;i<size;i++)
        {
            mp[nums[i]]++;
        }

  map<int, int>::iterator it;

        for(it =mp.begin();it!=mp.end();it++)
        {
            if(it->second > size/3)
            {
                ans.push_back(it->first);

            }

        }
        return ans;
    }
};