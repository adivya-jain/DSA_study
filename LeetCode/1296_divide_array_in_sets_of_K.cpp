// leetcode 1296. Divide Array in Sets of K Consecutive Numbers
// Given an array of integers nums and a positive integer k, check whether it is possible to divide this array into sets of
// k consecutive numbers.
// Return true if it is possible. Otherwise, return false.

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int size = nums.size();
        if(size%k!=0)
        {
            return false;
        }
        map<int,int> mp;

        for(int i = 0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }


        while(mp.size())
        {
            int minele = mp.begin()->first;

            for(int i = 0;i<k;i++)
            {
                if(mp[minele+i]> 0)
                {
                    mp[minele+i]--;
                    if(mp[minele+i]==0)
                    {
                        mp.erase(minele+i);
                    }
                } else{
                    return false;
                }
            }
        }





        return true;
    }
};