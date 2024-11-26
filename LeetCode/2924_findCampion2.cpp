class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {

        map<int, int> indegree;

        vector<int> ans;
        if (edges.size() < n - 1)
            return -1; // Not enough edges for a connected graph
        if (edges.empty())
            return n == 1 ? 0 : -1;
        for (int i = 0; i < n; ++i) {
            indegree[i] = 0;
        }

        // Process edges
        for (const auto& edge : edges) {
            indegree[edge[1]]++; // Increment indegree for destination
        }
        for (auto edge : indegree) {
            if (edge.second == 0) {
                ans.push_back(edge.first);
            }
        }
        if (ans.size() != 1)
            return -1;
        return ans[0];
    }
};