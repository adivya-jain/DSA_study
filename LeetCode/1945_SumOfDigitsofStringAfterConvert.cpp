class Solution {
public:
    int getLucky(string s, int k) {
        string converted="";
        for (int i = 0; i < s.length(); i++) {
            int num = s[i] - 'a' + 1;
            converted+=to_string(num);
        }

        while (k) {
            int temp=0;
            for (int i = 0; i < converted.length(); i++) {
                temp += converted[i] - '0' ;
            }
            converted = to_string(temp);
            k--;
        }
        return stoi(converted);
    }
};