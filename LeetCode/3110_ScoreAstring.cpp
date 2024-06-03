
// 3110. Score of a String

class Solution {
public:
    int scoreOfString(string s) {
        int a;
        int b;

        int sum = 0;

        int i=0;
        int n = s.length();
for(int i=1;i<n;i++)
{

    a = s[i];
    b = s[i-1];
    sum = sum + abs(a-b);
}

return sum;
    }
};