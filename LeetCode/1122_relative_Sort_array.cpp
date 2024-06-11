// leetcode 1122. Relative Sort Array
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;
        for (int i = 0; i < arr1.size(); i++) {
            mp[arr1[i]]++;
        }
        int j = 0;
        vector<int> ans;
        for (int i = 0; i < arr2.size(); i++) {
            int element = arr2[i];
            int count = mp[element];

            while (count != 0) {
                ans.push_back(element);
                mp[element]--;
                count--;
            }
            if (mp[element] == 0)
                mp.erase(element);
        }

        for (auto it : mp) {
            while (it.second > 0) {
                ans.push_back(it.first);
                it.second --;
            }
        }

        return ans;
    }
};