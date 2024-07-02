class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans;
        vector<int> minArray;
        vector<int> maxArray;
        if(n>m)
        {
            minArray = nums2;
            maxArray = nums1;  
        }
        else
        {
            minArray = nums1;  
            maxArray = nums2; 
        }
        map<int,int> mp;
        for(int i = 0 ; i < minArray.size();i++)
        {
            mp[minArray[i]]++;
        }
        for(int i = 0 ; i< maxArray.size();i++)
        {
            if(mp.find(maxArray[i]) != mp.end() && mp[maxArray[i]] > 0)
            {
                mp[maxArray[i]]--;
                ans.push_back(maxArray[i]);
                
            }
        }
        return ans;
    }
};