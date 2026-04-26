class Solution {
public:
    int m, n;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool dfs(int x, int y, int px, int py, vector<vector<char>>& grid,
             vector<vector<bool>>& visited) {
        visited[x][y] = true;

        for (auto dir : dirs) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                grid[nx][ny] == grid[x][y]) {
                if (!visited[nx][ny]) {
                    if (dfs(nx, ny, x, y, grid, visited)) {
                        return true;
                    }
                } else if (!(nx == px && ny == py)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfs(i, j, -1, -1, grid, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};