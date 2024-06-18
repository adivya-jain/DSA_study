//Approach 1 slow
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int i, j = 0;
        int n = word1.length();
        int m = word2.length();
        int maxlength = max(n,m);
        while (i < n && j < m) {
            ans = ans + word1[i] ;
            ans = ans + word2[i] ;
            i++;
            j++;
        }
        while(i<n)
        {
            ans = ans+ word1[i];
            i++;
        }
        while(j<m)
        {
            ans = ans+ word2[j];
            j++;
        }

        return ans;
    }
};
//Approach 2 fast

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
         int n = word1.length();
        int m = word2.length();
        int maxlength = max(n,m);
       for(int i=0;i<maxlength;i++)
       {
        if(i<n)
        {
            ans+=word1[i];
        }
        if(i<m)
        {
            ans+=word2[i];
        }
       }

        return ans;
    }
};
