class Solution {
public:
    int reverse(int x) {
        int reversed = 0;
        while (x) {
            int temp = x % 10;
            if ((reversed > INT_MAX / 10) || (reversed < INT_MIN / 10)) {
                return 0;
            }
            x = x / 10;
            reversed = reversed * 10 + temp;
        }
        return reversed;
    }
};