class Solution {
public:
    int maxi = 0;
    int n, m;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void solve(int i, int j, int sum, vector<vector<int>>& grid) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return;
        }

        int tempGold = grid[i][j];
        sum += tempGold;
        maxi = max(maxi, sum);

        grid[i][j] = 0;

        for (auto& dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            solve(ni, nj, sum, grid);
        }

        grid[i][j] = tempGold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    solve(i, j, 0, grid);
                }
            }
        }
        return maxi;
    }
};