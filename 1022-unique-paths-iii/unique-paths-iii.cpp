class Solution {
public:
    int n, m, nonObstacle;
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    void backtrack(int x, int y, int cnt, vector<vector<int>>& grid, int& ans) {
        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == -1) {
            return;
        }

        if (grid[x][y] == 2) {
            if (cnt == nonObstacle) {
                ans++;
            }
            return;
        }

        grid[x][y] = -1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            backtrack(nx, ny, cnt + 1, grid, ans);
        }
        grid[x][y] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        nonObstacle = 0;

        int x, y;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    nonObstacle++;
                } else if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                    nonObstacle++;
                }
            }
        }

        int cnt = 0;
        int ans = 0;

        backtrack(x, y, 0, grid, ans);
        return ans;
    }
};