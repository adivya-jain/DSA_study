class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        int k=0;
        for(int i=0;i<n1 && k<n2;i++)
        {
            if(str1[i] == str2[k] || str1[i]+1 == str2[k] || str1[i]-25 == str2[k])
            {
                k++;
            }
        }
        return k == n2;
    }
};