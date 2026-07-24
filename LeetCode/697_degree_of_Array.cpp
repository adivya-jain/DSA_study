// USING STRUCT
class Solution {
public:
struct Info{
    int freq=0;
    int first=-1;
    int last=-1;
};

    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, Info> mp;
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
            auto &info = mp[nums[i]];
            int ele = nums[i];
            maxi = max(maxi,++info.freq);
            if (info.first == -1) {
                info.first = i;
            }
            info.last = i;
        }
        int mini = nums.size();
        for(auto &[num,info]:mp)
        {
            if(info.freq == maxi)
            {
                mini = min(mini,info.last - info.first +1);
            }
        }
        return mini;
    }
};

// WITHOUT USING STRUCT
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
            int ele = nums[i];

            if (mp.find(ele) == mp.end()) {
                mp[ele] = {0, -1, -1};
            }
            maxi = max(maxi,++mp[ele][0]);
            if (mp[ele][1] == -1) {
                mp[ele][1] = i;
            }
            mp[ele][2] = i;
        }
        int mini = nums.size();
        for(auto it = mp.begin();it!=mp.end();it++)
        {
            if(it->second[0] == maxi)
            {
                mini = min(mini,it->second[2] - it->second[1]+1);
            }
        }
        return mini;
    }
};