class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> chars;
int count= 0;
        for(int i=0;i<s.length();i++)
        {
            char ch = s[i];
            if(!chars.empty() && chars.top() == 'b' && ch=='a')
            {
                count++;
                chars.pop();

            }
            else{
                chars.push(ch);
            }
        }
        return count;
    }
};