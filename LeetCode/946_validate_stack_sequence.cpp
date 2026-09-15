class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        int j = 0;
        stack<int> st;
        while (i < pushed.size()) {
            st.push(i);
            i++;
            while (!st.empty() && pushed[st.top()] == popped[j]) {
                st.pop();
                j++;
            }
        }
        return j == popped.size();
    }
};