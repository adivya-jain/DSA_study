class Solution {
    int solve(int a, int b) {
        if(a == 0) return b;
        return solve(b % a, a);
    }
public:
    string fractionAddition(string expression) {
        int num = 0;
        int deno = 1;
        int i = 0;

        while (i < expression.length()) {
            bool negative = false;
            if (expression[i] == '-' || expression[i] == '+') {
                negative = (expression[i] == '-');
                i++;
            }

            int currnum = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                currnum = currnum * 10 + (expression[i] - '0');
                i++;
            }
            i++; // Skip the '/'
            int currdeno = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                currdeno = currdeno * 10 + (expression[i] - '0');
                i++;
            }

            num = num * currdeno + (negative ? -1 : 1) * currnum * deno;
            deno = deno * currdeno;
        }

        int commondivisor = solve(abs(num), deno);
        num /= commondivisor;
        deno /= commondivisor;

        return std::to_string(num) + "/" + std::to_string(deno);
    }
};
