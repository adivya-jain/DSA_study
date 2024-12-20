//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
        // code here
        if(n==0 || n==1) return 1;
        int a=1,b=1;
        int mod=1000000007;
        
        int sum;
        int c;
        for(int i=0;i<n-2;i++)
        {
            c=(a+b)%mod;
            a=b%mod;
            b=c%mod;
        }
        return c%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends