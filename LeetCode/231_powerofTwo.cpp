class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count = 0;
        if(n==0) return false;
        while(n)
        {
            if(n&1)
                count++;
            if(count > 1) return false;
            n>>=1;
        }
        return true;
    }
};