class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    int n, m;

    void dfs(int x, int y, vector<vector<char>>& grid,
             vector<vector<bool>>& visited) {
        visited[x][y] = true;

        for (int i = 0; i < 4; i++) {

            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] &&
                grid[nx][ny] == '1') {
                dfs(nx, ny, grid, visited);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return cnt;
    }
};