class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degrees(n, 0);
        for (vector<int> it : roads) {
            degrees[it[0]]++;
            degrees[it[1]]++;
        }

        sort(degrees.begin(), degrees.end()); // Sort in descending order

        long long ans = 0;
        for (int i = 0; i < degrees.size(); i++) {
            ans += degrees[i] * (i + 1); // Multiply the degree by its position
        }

        return ans;
    }
};