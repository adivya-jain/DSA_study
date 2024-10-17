class Solution {
    int recu(int index,vector<int>&nums,int currOr,int targetOr)
    {
        if(index == nums.size())
        {
            return currOr==targetOr?1:0;
        }

        int inc = recu(index+1,nums,currOr|nums[index],targetOr);
        int noinc = recu(index+1,nums,currOr,targetOr);

        return inc+noinc;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int index=0;
        int currOr = 0;
        int targetOr=0;
        for(int i =0;i<nums.size();i++)
        {
            targetOr |= nums[i];
        }
        return recu(index,nums,currOr,targetOr);
    }
};