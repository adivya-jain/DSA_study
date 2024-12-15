//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        priority_queue<int,vector<int>,greater<int>> pq;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++)
        {
            if(i>0 && arr[i]==arr[i-1])
            {
            continue;
            }
            pq.push(arr[i]);
            if(pq.size() > 2) pq.pop();
        }
        if(pq.size() == 2)
        {
            return pq.top();
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends