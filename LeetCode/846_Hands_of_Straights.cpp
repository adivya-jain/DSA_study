// leetcode 846. Hands of Straights
// Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, 
// and consists of groupSize consecutive cards.
// Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, 
// return true if she can rearrange the cards, or false otherwise.

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int size = hand.size();
        if(size%groupSize!=0)
        {
            return false;
        }
        map<int,int> mp;

        for(int i = 0;i<hand.size();i++)
        {
            mp[hand[i]]++;
        }


        while(mp.size())
        {
            int minele = mp.begin()->first;

            for(int i = 0;i<groupSize;i++)
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