
class Solution {
public:
    void dfs(int i, int j, int init, int m, int n,
             vector<vector<int>>& image, int color) {

        image[i][j] = color;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && x < m && y >= 0 && y < n &&
                image[x][y] == init) {
                dfs(x, y, init, m, n, image, color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        int init = image[sr][sc];

        if (init == color) return image;

        dfs(sr, sc, init, m, n, image, color);
        return image;
    }
};
