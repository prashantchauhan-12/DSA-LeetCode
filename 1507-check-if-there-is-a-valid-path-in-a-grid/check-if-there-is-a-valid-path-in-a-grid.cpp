class Solution {
public:
    // Directions: {row_offset, col_offset}
    // We map each pipe type to the two directions it connects
    vector<vector<vector<int>>> dirs = {
        {},                 // 0 unused
        {{0, -1}, {0, 1}},  // 1: left, right
        {{-1, 0}, {1, 0}},  // 2: up, down
        {{0, -1}, {1, 0}},  // 3: left, down
        {{0, 1}, {1, 0}},   // 4: right, down
        {{0, -1}, {-1, 0}}, // 5: left, up
        {{0, 1}, {-1, 0}}   // 6: right, up
    };

    bool dfs(int r, int c, vector<vector<int>>& grid,
             vector<vector<bool>>& visited) {
        int m = grid.size();
        int n = grid[0].size();

        if (r == m - 1 && c == n - 1)
            return true;
        visited[r][c] = true;

        for (auto& dir : dirs[grid[r][c]]) {
            int nr = r + dir[0];
            int nc = c + dir[1];

            // 1. Check Bounds
            // 2. Check if already visited
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                // 3. Connection Check: Does the next cell connect back to the
                // current one?
                for (auto& nextDir : dirs[grid[nr][nc]]) {
                    if (nr + nextDir[0] == r && nc + nextDir[1] == c) {
                        if (dfs(nr, nc, grid, visited))
                            return true;
                    }
                }
            }
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(0, 0, grid, visited);
    }
};