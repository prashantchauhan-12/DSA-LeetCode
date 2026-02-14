class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Check neighbors
                bool isPeak = true;

                // Check Top
                if (i > 0 && mat[i][j] < mat[i - 1][j])
                    isPeak = false;
                // Check Bottom
                if (i < rows - 1 && mat[i][j] < mat[i + 1][j])
                    isPeak = false;
                // Check Left
                if (j > 0 && mat[i][j] < mat[i][j - 1])
                    isPeak = false;
                // Check Right
                if (j < cols - 1 && mat[i][j] < mat[i][j + 1])
                    isPeak = false;

                if (isPeak) {
                    return {i, j};
                }
            }
        }
        return {-1, -1}; // Should not reach here per problem constraints
    }
};