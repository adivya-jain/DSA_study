class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;
        int maxcnt=0;
        for(char x:s)
        {
            if(x =='(') cnt++;
            maxcnt = max(cnt,maxcnt);
            if(x==')') cnt--;
           
        }
        return maxcnt;
    }
};