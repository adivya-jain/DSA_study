class Solution {

    void reverse(stack<char>& st) {
        string temp = "";
        while (!st.empty() && st.top() != '(') {
            temp += st.top();
            st.pop();
        }
        st.pop();
        for (char c : temp) {
            st.push(c);
        }
    }

public:
    string reverseParentheses(string s) {
        string ans = "";
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')') {
                reverse(st);
            } else {
                st.push(s[i]);
            }
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        ::reverse(ans.begin(), ans.end());
        return ans;
    }
};