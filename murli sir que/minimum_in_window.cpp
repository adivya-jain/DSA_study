#include <bits/stdc++.h>
using namespace std;

// Return minimum element for every window of size k
vector<int> findMinimums(vector<int>& arr, int k) {
    
    vector<int> ans;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=0;i<k;i++)
    {
        pq.push(make_pair(arr[i],i));
    }
    
    ans.push_back(pq.top().first);
    for(int i=k;i<arr.size();i++)
    {
        pq.push(make_pair(arr[i],i));
        pair<int,int> top = pq.top();
        while(!pq.empty() && pq.top().second < i - k + 1) {
            pq.pop();
        }
        ans.push_back(pq.top().first);
    }
    
    return ans;
}

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    vector<int> ans = findMinimums(arr, k);

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}