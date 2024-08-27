#include<iostream>
class Solution {
    
public:
    int fib(int n) {

        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return 1;
        }


        int sum=fib(n-1)+fib(n-2);

        return sum;
        
    }
};
//
class Solution {
    int solve(int n, int n1, int n2) 
    {
        if(n==0) return n1+n2;
        return solve(n-1,n2,n1+n2);
    }

public:
    int fib(int n) {
        int n1 = 0;
        int n2 = 1;
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int ans = solve(n - 2, n1, n2);
        return ans;
    }
};