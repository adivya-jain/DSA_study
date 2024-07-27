#include <algorithm>
#include <string>
#include <vector>
class Solution {
private:
    static constexpr int INF = 1e9;
    vector<vector<int>> buildConversionGraph(vector<char>& original,
                                             vector<char>& changed,
                                             vector<int>& cost) {
        vector<vector<int>> graph(26, vector<int>(26, INF)); // marking infinity
        for (int i = 0; i < 26; i++) {
            graph[i][i] = 0; // self loop 0
        }
        for (int j = 0; j < original.size(); j++) {
            int from = original[j] - 'a';
            int to = changed[j] - 'a';
            graph[from][to] = min(graph[from][to], cost[j]);
        } // direct conversions
        return graph;
    }
    void optimizeConversionPaths(vector<vector<int>> &graph) {
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                if (graph[i][k] < INF) {
                    for (int j = 0; j < 26; j++) {
                        if (graph[k][j] < INF) {
                            graph[i][j] =
                                min(graph[i][j], graph[i][k] + graph[k][j]);
                        }
                    }
                }
            }
        }
    }
    long long computeConversionCost(vector<vector<int>> &graph, string &source,
                                    string &target) {
        long long ans = 0;

        for (int i = 0; i < source.length(); i++) {
            int from = source[i] - 'a';
            int to = target[i] - 'a';
            if (from != to) {
                if (graph[from][to] == INF) {
                    return -1;
                }
                ans += graph[from][to];
            }
        }
        return ans;
    }

public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> conversionGraph =
            buildConversionGraph(original, changed, cost);
        optimizeConversionPaths(conversionGraph);
        // floyd warshall algorithm
        return computeConversionCost(conversionGraph, source, target);
    }
};

// this code not correct because their can if their is no path from a->b but we
// can go to b via another paths so this is an graph problem
//  class Solution {
//  public:
//      long long minimumCost(string source, string target, vector<char>&
//      original,
//                            vector<char>& changed, vector<int>& cost) {

//         map<pair<char, char>, int> mapping;
//         int n = cost.size();
//         for (int i = 0; i < n; i++) {
//             pair<char, char> temp = make_pair(original[i], changed[i]);
//             if (mapping.find(temp) != mapping.end()) {
//                 mapping[temp] = min(mapping[temp], cost[i]);
//             } else {
//                 mapping[temp] = cost[i];
//             }
//         }

//         long long ans = 0;

//         int j = 0;
//         while (j++ < source.length()) {
//             pair<char, char> temp = make_pair(source[j], target[j]);
//             if (source[j] == target[j]) {
//                 continue;
//             } else if (mapping.find(temp) != mapping.end()) {
//                 ans += mapping[temp];

//             } else {
//                 return -1;

//             }
//         }
//         return ans;
//     }
// };