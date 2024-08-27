// BELLMAN FORD
//SHORTEST PATH ALORITHM
// Time Complexity: O(n^2)
// Space Complexity: O(n)
// n: number of nodes
// edges.size() = succProb.size()
// edges.size() <= 10^5
// succProb.size() <= 10^5
// edges[i].size() = 2
// succProb[i] is a double value
// start_node, end_node < n
// 0 <= succProb[i] <= 1
// 0 <= edges[i][0], edges[i][1] < n
// 0 <= n <= 10^5
// 0 <= start_node, end_node < n
// 0 <= i < edges.size()


class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        vector<double> prob(n);
        prob[start_node] = 1;
        for (int i = 0; i < n - 1; i++) {
            bool changed = false;
            int j = 0;
            for (auto edge : edges) {
                int u = edge[0];
                int v = edge[1];
                double sp = succProb[j];
                if (prob[u] * sp > prob[v]) {
                    prob[v] = prob[u] * sp;
                    changed = true;
                }
                if (prob[v] * sp > prob[u]) {
                    prob[u] = prob[v] * sp;
                    changed = true;
                }
                
                j++;
            }
            if(!changed) break;
        }
        return prob[end_node];
    }
};