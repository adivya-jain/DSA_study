class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int i = 0;
        while (num) {
            if (!(num & 1))
                ans += (1) * pow(2, i);
            i++;
            num >>=1;
        }
        return ans;
    }
};
