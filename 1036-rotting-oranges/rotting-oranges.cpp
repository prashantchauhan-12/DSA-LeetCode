class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        int freshOranges = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    freshOranges++;
                }

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int minutes = 0;
        while (!q.empty()) {
            if (freshOranges == 0) {
                break;
            }

            minutes++;
            int len = q.size();
            for (int c = 0; c < len; c++) {
                auto [x, y] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                        !visited[nx][ny] && grid[nx][ny] == 1) {
                        q.push({nx, ny});
                        visited[nx][ny] = 1;
                        freshOranges--;
                    }
                }
            }
        }

        return (freshOranges == 0) ? minutes : -1;
    }
};