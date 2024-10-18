class Solution {

    void invert(string& str) {
        for(int i=0;i<str.length();i++)
        {
            str[i]= str[i]=='1'?'0':'1';
        }
        
    }
    string func(string str) { 
        invert(str); 
        reverse(str.begin(), str.end());
        return str;
    }
    string recur(int n)
    {
        if(n==1)
        {
            return "0";
        }
        string add = recur(n-1);
        string ans = add + '1' + func(add);

        return ans;
    }

public:
    char findKthBit(int n, int k) {
        if(n==1) return '0';
        string ans = recur(n);
        return ans[k-1];
    }
};