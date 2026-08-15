class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        bool positive = true;
        bool digitnotstarted = true;

        for (int i = 0; i < s.length(); i++) {

            // Leading spaces
            if (digitnotstarted && s[i] == ' ') {
                continue;
            }

            // Sign
            if (digitnotstarted && (s[i] == '-' || s[i] == '+')) {
                positive = (s[i] == '+');
                digitnotstarted = false;
                continue;
            }

            // Digit
            if (s[i] >= '0' && s[i] <= '9') {
                int digit = s[i] - '0';

                if (positive) {
                    if (ans > (INT_MAX - digit) / 10)
                        return INT_MAX;
                } else {
                    if (ans > ((long long)INT_MAX + 1 - digit) / 10)
                        return INT_MIN;
                }

                ans = ans * 10 + digit;
                digitnotstarted = false;
            }
            else {
                break;
            }
        }

        return positive ? ans : -ans;
    }
};