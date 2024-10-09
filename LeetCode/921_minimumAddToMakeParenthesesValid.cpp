class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> str;
        int count =0;
        for(int i=0;i<s.length();i++)
        {
            char ch = s[i];

            if(ch == '(')
            {
                str.push(ch);
                count ++;
            }
            else{
                if(!str.empty()){ str.pop();  count--;}
                else{
                    count++;
                } 
            }
        }
        return count;
    }
};