class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        map<int, int> mp;
        vector<int> ans;
        vector<int> greater(nums2.size(),-1);
        int maxi = 0;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            mp[nums2[i]] = i;
            if(nums2.size()==0)
            {
                st.push(nums2[i]);
                greater[i] = -1;
            }else{
               while(!st.empty() && st.top() < nums2[i])
               {
                 st.pop();
               }
               if(!st.empty())
               {
                greater[i] = st.top();
               }else{
                    greater[i] = -1;
               }

               st.push(nums2[i]);
            }
        }


        for(int i=0;i<nums1.size();i++)
        {
            int index = mp[nums1[i]];
            ans.push_back(greater[index]);
        }
        return ans;
    }
};