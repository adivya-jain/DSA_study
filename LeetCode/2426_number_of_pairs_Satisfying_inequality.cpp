class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<long long> dif(n);
        for(int i=0;i<n;i++)
        {
            dif[i]=(long long)nums1[i] - nums2[i];
        }

        vector<long long> cc = dif;
        
        sort(cc.begin(),cc.end());
        cc.erase(unique(cc.begin(),cc.end()),cc.end());
        
        int m = cc.size();
        vector<int> bit(m+1,0);

        auto update=[&](int i)
        {
            for(;i<=m;i+=i&-i)
            {
                bit[i]++;
            }
        };

        auto query=[&](int i)
        {
            int cnt=0;
            for(;i>0;i-=i&-i)
            {
                cnt+=bit[i];
            }
            return cnt;
        };
        long long ans=0;

        for(int i=0;i<n;i++)
        {
           long long target = dif[i]+diff;

           int idx = upper_bound(cc.begin(),cc.end(),target)-cc.begin();
           ans+=query(idx);//number of values smaller than target
           int idx1 =lower_bound(cc.begin(),cc.end(),dif[i])-cc.begin()+1;
            update(idx1);
        }
        return ans;
    }
};