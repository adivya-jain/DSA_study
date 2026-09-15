class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        //using vector insteas of monotonic stack
        for (char digit : num) {
            while (st.size() != 0 && k > 0 && st.back() > digit) {
                st.pop_back();
                k--;
            }
            st.push_back(digit);
        }
        // if k is still left, remove from right this case arrives when
        // array is already monotonic increasing
        while (k > 0) {
            st.pop_back();
            k--;
        }

        int pos = 0;
        while (pos < st.size() && st[pos] == '0') {
            pos++;
        }
        if (pos == st.size())
            return "0";

        return st.substr(pos);
    }
};