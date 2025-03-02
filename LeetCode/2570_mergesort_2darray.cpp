class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int l=0;
        int r=0;
        vector<vector<int>> ans;
        while(l<n && r<m)
        {
            if(nums1[l][0] == nums2[r][0]) 
            {
                ans.push_back({ nums1[l][0],nums1[l][1]+nums2[r][1]});
                l++;
                r++;
            }
            else if(nums1[l][0] < nums2[r][0]) 
            {
                ans.push_back({ nums1[l][0],nums1[l][1]}); l++;
            }
            else {
                ans.push_back({nums2[r][0],nums2[r][1]});  r++;
            }
        }
        while(l < n)
        {
            ans.push_back(nums1[l]);
            l++;
        }
        while(r<m)
        {
            ans.push_back(nums2[r]);
            r++;
        }
        return ans;
    }
};
// map method
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> mp;
        for(auto num:nums1)
        {
            mp[num[0]] += num[1];
        }
         for(auto num:nums2)
        {
            mp[num[0]] += num[1];
        }
        vector<vector<int>> ans;
        
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            ans.push_back({it->first,it->second});
        }
        return ans;
    }
};
