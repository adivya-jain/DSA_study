class Solution {
public:
    int hammingWeight(int n) {
        int c=0;
        while(n)
        {   if(n&1)
                c+=1;
            n>>=1;
        }
        return c;
    }
};