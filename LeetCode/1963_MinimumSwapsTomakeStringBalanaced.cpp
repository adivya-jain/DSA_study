class Solution {
public:
    int minSwaps(string s) {
        stack<char> str;
        int count=0;
        for (int i = 0; i < s.length(); i++) {
            if(s[i]=='[')
                str.push('[');
            else {
                if(!str.empty()) str.pop();
                else count++;
            }
        }

        return (count+1)/2;
    }
};