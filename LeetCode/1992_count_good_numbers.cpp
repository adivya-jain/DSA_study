class Solution {
public:
    int ans(long long cnt, long long n) {

        if (n == 0)
            return 1;

        if (n % 2 == 0)
            return ans((cnt * cnt) % 1000000007, n / 2);

        return (cnt % 1000000007) *
               ans((cnt * cnt) % 1000000007, n / 2) %
               1000000007;
    }

    int countGoodNumbers(long long n) {

        long long cnt = 20;

        if (n % 2 == 1)
            return (5LL * ans(cnt, (n - 1)/2)) % 1000000007;

        return ans(cnt, n/2);
    }
};