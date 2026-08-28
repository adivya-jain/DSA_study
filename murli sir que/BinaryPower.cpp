#include <bits/stdc++.h>
using namespace std;

/*
    Problem:
    Calculate x^n efficiently.

    Learn these approaches:
    1. n is given in binary
    2. n is given in decimal
    3. Convert decimal n -> binary, then calculate x^n
*/

// ------------------------------------------------------------
// 1. n is given as BINARY
// Example: x = 3, n = "1011"  -> 3^11
// ------------------------------------------------------------
long long powerBinaryRecursion(long long x, long long n)
{
    // TODO
    if(n<1) return 1;
    if(n%2)
    {
        return x*powerBinaryRecursion(x*x,n/2);
    }else{
        return powerBinaryRecursion(x*x,n/2);
    }

    return 0;
}
long long powerBinaryIterative(long long x, long long n)
{
    long long y =1;
    while(n)
    {
        if(n%2 == 1)
        {
            y = y*x;
        }

        x = x*x;
        n = n/2;
    }
    return y;


}



// ------------------------------------------------------------
// 2. n is given as DECIMAL
// Example: x = 3, n = "11" -> 3^11
// n can be VERY large, so use string.
// ------------------------------------------------------------
long long powerDecimal(long long x, vector<int> n)
{
    long long y = 1;
    const long long MOD = 1000000007;
    for(int i = 0; i < n.size(); i++)
    {
        // y = y^10
        long long z = (y * y) % MOD;   // y^2
        y = (z * z)%MOD;             // y^4
        y = (y * y)%MOD;             // y^8
        y = (y * z)%MOD;             // y^10

        // multiply by x^digit
        for(int j = 0; j < n[i]; j++)
        {
            y = (y * x) % MOD;
        }
    }

    return y;
}

// ------------------------------------------------------------
// 3. Convert DECIMAL -> BINARY
// Example: "11" -> "1011"
// ------------------------------------------------------------
long long decimalToBinary(long long n)
{
    // TODO
    return 0;
}


int main()
{
    // Test cases
    long long x = 3;

    long long binaryN = 33;
    // long long decimalN = 11;
    vector<int> decimalN = {3,8,9,9,9,5,3,2,5,3,2,4,5,6,7,8,9,5,4,2};

    cout << "Binary exponentiation Using Recursion: "
         << powerBinaryRecursion(x, binaryN) << endl;

         
    cout << "Binary exponentiation Using Iteration: "
         << powerBinaryIterative(x, binaryN) << endl;


    cout << "Decimal exponentiation: "
         << powerDecimal(x, decimalN) << endl;

    // cout << "Decimal to Binary: "
    //      << decimalToBinary(decimalN) << endl;

    return 0;
}