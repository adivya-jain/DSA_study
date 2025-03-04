class Solution {
    // pair<int, int> range(vector<int> position) {
    //     int maxi = INT_MIN;
    //     int mini = INT_MAX;
    //     for (int i = 0; i < position.size(); i++) {
    //         mini = min(mini, position[i]);
    //         maxi = max(maxi, position[i]);
    //     }

    //     return make_pair(mini,maxi);
    // }

public:

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 1, r = position.back() - position[0];
        int ans = -1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int lastPosition = position[0], balls = 1;
            for(int i = 1; i < position.size(); i++) {
                if(position[i] - lastPosition >= mid) {
                    lastPosition = position[i];
                    balls++;
                }
            }
            if(balls >= m) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};