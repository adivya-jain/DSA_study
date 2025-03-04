// 648. Replace Words

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string> st;
        string word = "";
        string ans = "";
        sentence += " ";
        for(auto i :dictionary)
        {
            st.insert(i);
        }

        for(auto i:sentence)
        {
            if(i==' ')
            {
                if(ans.size()>0) ans+=' ';
                string temp="";
                for(auto j:word)
                {
                    temp+=j;
                    if(st.count(temp))
                    {
                        break;
                    }
                }
                ans +=temp;
                word="";
            }else word += i;
        }

        return ans;
    }

};