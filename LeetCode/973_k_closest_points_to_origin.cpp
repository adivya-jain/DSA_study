class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            int distA = a[0] * a[0] + a[1] * a[1];
            int distB = b[0] * b[0] + b[1] * b[1];

            return distA < distB;
        };

        sort(points.begin(), points.end(), cmp);
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};




class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < points.size(); i++) {
            pq.push({points[i][0] * points[i][0] + points[i][1] * points[i][1],
                     points[i][0], points[i][1]});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            vector<int> temp = pq.top();
            ans.push_back({temp[1], temp[2]});
            pq.pop();
        }
        return ans;
    }
};


class Solution { // using STL nth_element Quick Select
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto dis = [](const vector<int>& a) {
            return 1LL * a[0] * a[0] + 1LL * a[1] * a[1];
        };

        nth_element(points.begin(), points.begin() + k, points.end(),
                    [&](const vector<int>& a, const vector<int> b) {
                        return dis(a) < dis(b);
                    });

        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};