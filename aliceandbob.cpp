
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> st;
    int n, k;

    int nextgreater(int node, int ss, int se, int pos, int val) {
        if (se <= pos || st[node] <= val)
            return -1;

        if (ss == se)
            return ss;

        int mid = (ss + se) / 2;

        int left = nextgreater(2 * node + 1, ss, mid, pos, val);

        if (left != -1)
            return left;

        return nextgreater(2 * node + 2, mid + 1, se, pos, val);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        n = heights.size();
        k = 1;

        while (k < n)
            k *= 2;

        st.assign(2 * k - 1, INT_MIN);

        for (int i = 0; i < n; i++)
            st[k - 1 + i] = heights[i];

        for (int i = k - 2; i >= 0; i--)
            st[i] = max(st[2 * i + 1], st[2 * i + 2]);

        vector<int> ans;

        for (auto& q : queries) {
            int a = min(q[0], q[1]);
            int b = max(q[0], q[1]);

            if (a == b || heights[b] > heights[a]) {
                ans.push_back(b);
            } else {
                ans.push_back(
                    nextgreater(0, 0, k - 1, b, heights[a])
                );
            }
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++)
        cin >> heights[i];

    int q;
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(2));

    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }

    Solution obj;
    vector<int> ans = obj.leftmostBuildingQueries(heights, queries);

    for (int x : ans)
        cout << x << endl;

    return 0;
}
