class Solution {
public:
    int product(int n) {
        int prod = 1;
        while (n) {
            prod = prod *  (n % 10);
            n = n / 10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        while (true) {
            int productOfDigits = product(n);
            if (productOfDigits % t == 0)
                return n;
            n++;
        }
    }
};