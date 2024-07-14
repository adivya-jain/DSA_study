class Solution {
public:
    string countOfAtoms(string s) {
        int n = s.size();
        vector<pair<string, int>> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push_back({string(1, s[i]), 0});
            } else if (s[i] == ')') {
                int mul = 0;
                while (i + 1 < n && isDigit(s[i + 1])) {
                    mul = mul * 10 + s[i + 1] - '0';
                    i++;
                }
                if (mul == 0)
                    mul = 1;

                vector<pair<string, int>> temp;

                while (stk.size() > 0 && stk.back().first != "(")
                {
                    pair<string, int>& p = stk.back();
                    stk.pop_back();
                    p.second *= mul;
                    temp.push_back(p);
                }

                stk.pop_back();

                for (auto& p : temp)
                    stk.push_back(p);
            } else {
                if (i + 1 < n) {
                    string name(1, s[i]);
                    int count = 0;
                    if (isLower(s[i + 1])) {
                        name += s[i + 1];
                        i++;
                    }
                    while (i + 1 < n && isDigit(s[i + 1])) {
                        count = count * 10 + s[i + 1] - '0';
                        i++;
                    }

                    if (count == 0)
                        count = 1;
                    stk.push_back({name, count});
                } else {
                    stk.push_back({string(1, s[i]), 1});
                }
            }
        }

        map<string,int> mp;
        for(auto& p: stk) mp[p.first] +=p.second;

        string ans;
        for(auto it = mp.begin();it!=mp.end();it++)
        {
            ans+=it->first;
            if(it->second > 1) ans+=to_string(it->second);

        }
        return ans;
    }

    bool isDigit(char c)
    {
        return c-'0' >=0 && c-'0' <=9;
    }
    bool isUpper(char c)
    {
        return c-'A' >=0 && c-'A' <=25;
    }
    bool isLower(char c)
    {
        return c-'a' >=0 && c-'a' <=25;
    }


};