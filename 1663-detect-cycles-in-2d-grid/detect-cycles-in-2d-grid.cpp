class Solution {
public:
    int m, n;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {

                    queue<pair<pair<int, int>, pair<int, int>>> q;
                    q.push({{i, j}, {-1, -1}});
                    visited[i][j] = true;

                    while (!q.empty()) {
                        auto [current, parent] = q.front();
                        q.pop();

                        int x = current.first;
                        int y = current.second;

                        for (auto dir : dirs) {
                            int nx = x + dir.first;
                            int ny = y + dir.second;

                            if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                                grid[nx][ny] == grid[x][y]) {
                                if (!visited[nx][ny]) {
                                    visited[nx][ny] = true;
                                    q.push({{nx, ny}, {x, y}});
                                } else if (!(nx == parent.first &&
                                             ny == parent.second)) {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};