class Solution {
public:
    bool check(int start,string s,string goal, int n)
    {
        int k=0;
        for(int j=0;j<n;j++)
        {
            int i = (start + j) %n;
            if(s[k] != goal[i])
            {
                return false;
            }
            k++;
        }
        return true;
    }
    bool rotateString(string s, string goal) {
        int slen = s.length();
        int glen = goal.length();

        if(slen != glen) return false;
        int i = 0;
        char start = s[0];
        while(i<slen)
        {
            if(start == goal[i])
            {
                if(check(i,s,goal,slen))
                {
                    return true;
                }
            }

            i++;
        }

        return false;
    }
};