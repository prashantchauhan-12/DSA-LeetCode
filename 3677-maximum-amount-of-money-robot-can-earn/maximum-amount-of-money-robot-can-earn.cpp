class Solution {
public:
    int m, n;
    int dp[501][5001][3];

    int solve(int i, int j, int count, vector<vector<int>>& coins) {
        if (i == m - 1 && j == n - 1) {
            if (coins[i][j] < 0 && count > 0)
                return 0;
            else
                return coins[i][j];
        }

        if (i >= m || j >= n)
            return -1e9;

        if (dp[i][j][count] != -1e9)
            return dp[i][j][count];

        // take freebie
        int take = -1e9;
        if (coins[i][j] < 0 && count > 0) {
            take = max(solve(i + 1, j, count - 1, coins),
                       solve(i, j + 1, count - 1, coins));
        }

        // nottake freebie
        int nottake = 0;
        nottake = coins[i][j] + max(solve(i + 1, j, count, coins),
                                    solve(i, j + 1, count, coins));

        return dp[i][j][count] = max(take, nottake);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < 3; k++)
                    dp[i][j][k] = -1e9;
        return solve(0, 0, 2, coins);
    }
};