
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> que;
        int fresh = 0, time = 0;

        // Add all rotten oranges initially
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2)
                    que.push({i,j});

                if(grid[i][j] == 1)
                    fresh++;
            }
        }

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        while(!que.empty() && fresh > 0) {
            int sz = que.size();

            for(int i = 0; i < sz; i++) {
                auto [x,y] = que.front();
                que.pop();

                for(int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if(nx >= 0 && nx < m && ny >= 0 && ny < n &&
                       grid[nx][ny] == 1) {

                        grid[nx][ny] = 2;
                        fresh--;
                        que.push({nx,ny});
                    }
                }
            }

            time++;
        }

        return fresh == 0 ? time : -1;
    }
};
