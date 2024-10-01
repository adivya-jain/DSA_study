class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int> moduloCount;
        for(int i=0;i<arr.size();i++)
        {
            int mod = (arr[i]%k + k) % k;
            moduloCount[mod] ++;
        }

        for(auto it = moduloCount.begin();it!=moduloCount.end();it++)
        {
            int mod = it->first;
            int count = it->second;
             if (mod == 0) {
                if (count % 2 != 0) {
                    return false;
                }
            }
            else if (moduloCount[mod] != moduloCount[k - mod]) {
                return false;
            }
            
        }
        return true;
    }
};