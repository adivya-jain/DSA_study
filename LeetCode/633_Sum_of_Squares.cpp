//Approach 1
class Solution {
public:
    bool judgeSquareSum(int c) {
        int end = pow(c,0.5);
        int start = 0;
        // int end = sqr;
        while(start<=end)
        {
            long long int sum = pow(start,2)+pow(end,2);
            if(sum == c)
            {
                return true;
            }
            else if(sum>c)
            {
                end--;
            }
            else{
                start++;
            }
        }
        return false;
    }
};

//Approach 2
class Solution {
public:
    bool judgeSquareSum(int c) {
        int sqr = pow(c,0.5);
        int b2;
        for(int a = 0;a<sqr+1;a++)
        {
            b2 = c - pow(a,2);
            int b2sqr = pow(b2,0.5);
            if(b2sqr*b2sqr == b2)
            {
                return true;
            }
        }
        return false;
    }
};