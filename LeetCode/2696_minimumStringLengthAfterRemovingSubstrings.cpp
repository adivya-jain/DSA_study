class Solution {
public:
    int minLength(string s) {
        stack<char> remain;

        for(int i=0;i<s.size();i++)
        {
            if(remain.empty())
            {
                remain.push(s[i]);
            }
            else if((remain.top() == 'A' && s[i]=='B') || remain.top()=='C' && s[i]=='D')
            {
                remain.pop();
            }
            else{
                remain.push(s[i]);
            }
        }

        return remain.size();
    }
};