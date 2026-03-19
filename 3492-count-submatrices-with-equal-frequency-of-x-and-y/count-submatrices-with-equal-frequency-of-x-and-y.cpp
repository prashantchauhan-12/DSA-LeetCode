class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> countX(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> countY(n + 1, vector<int>(m + 1, 0));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Carry over prefix sums using Inclusion-Exclusion Principle
                countX[i + 1][j + 1] = countX[i][j + 1] + countX[i + 1][j] -
                                       countX[i][j] + (grid[i][j] == 'X');

                countY[i + 1][j + 1] = countY[i][j + 1] + countY[i + 1][j] -
                                       countY[i][j] + (grid[i][j] == 'Y');

                if (countX[i + 1][j + 1] == countY[i + 1][j + 1] &&
                    countX[i + 1][j + 1] > 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};