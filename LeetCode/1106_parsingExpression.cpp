class Solution {
public:
    bool parseBoolExpr(string expression) {
        bool ans;
        bool krnaha = true;
        // ! & | ( f t)
        stack<char> st;
        stack<char> exp;
        // st.push('Y');
        int i = 0;
        while (i < expression.size()) {
            char ch = expression[i];
            if (ch == '(' || ch == 't' || ch == 'f') {
                st.push(ch);
            } else if (ch == '!' || ch == '&' || ch == '|') {
                exp.push(ch);
            } else if (ch == ')') {
                vector<bool> vals; // To store all boolean values within the parentheses

                // Pop until we hit '(' and gather boolean values
                while (st.top() != '(') {
                    vals.push_back(st.top() == 't');
                    st.pop();
                }
                st.pop(); // Pop the '('

                // Get the operator for this expression
                char op = exp.top();
                exp.pop();

                bool result;
                if (op == '!') {
                    // Negation should apply to exactly one value
                    result = !vals[0];
                } else if (op == '&') {
                    // AND operator, all must be true
                    result = true;
                    for (bool val : vals) {
                        result &= val;
                    }
                } else if (op == '|') {
                    // OR operator, at least one must be true
                    result = false;
                    for (bool val : vals) {
                        result |= val;
                    }
                }

                // Push the result of the expression back onto the stack
                st.push(result ? 't' : 'f');
            }
            i++;
        }
        return st.top()=='t';
    }
};