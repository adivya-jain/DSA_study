class Solution {
public:
    int passThePillow(int n, int time) {
        int rem = time%(2*n-2);
        int index;
        if(rem+1 > n)
        {
            index = n - rem%n -1;
        }else index = rem+1;

        return index;
    }
};