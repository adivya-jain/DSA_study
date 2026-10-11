
// 2940. Find Building Where Alice and Bob Can Meet
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
                ans.push_back(nextgreater(0, 0, k - 1, b,
                                          heights[a]));
            }
        }

        return ans;
    }
};