
class Solution {
    int bfs(int n, vector<vector<int>> adjlist) {
        vector<bool> visited(n,false);
        queue<int> nodequeue;
        nodequeue.push(0);
        visited[0]=true;


        int layersExplored = 0;
        int currentLayerNodeCount = 1;
        int nextLayerNodeCount = 0;
        while (!nodequeue.empty()) {
            for (int i = 0; i < currentLayerNodeCount; ++i) {
                int currNode = nodequeue.front();
                nodequeue.pop();


                if (currNode == n - 1)
                    return layersExplored;

                for (auto node : adjlist[currNode]) {
                    if (visited[node])
                        continue;
                    nodequeue.push(node);
                    nextLayerNodeCount++;
                    visited[node] = true;
                }
                
            }
            currentLayerNodeCount = nextLayerNodeCount;
                nextLayerNodeCount = 0;
                layersExplored++;
            
        }
        return -1;
    }

public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<int> answer;
        vector<vector<int>> adjlist(n,vector<int>(0));
        for (int i = 0; i < n - 1; i++) {
            adjlist[i].push_back(i + 1);
        }
        adjlist[n - 1].push_back(-1);

        for (auto querie : queries) {
            int u = querie[0];
            int v = querie[1];
            adjlist[u].push_back(v);
            answer.push_back(bfs(n, adjlist));
        }
        return answer;
    }
};