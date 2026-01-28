class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int col0 = 1; // Extra marker for the first column

        // Step 1: Mark rows and columns
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // Mark the row
                    if (j != 0)
                        matrix[0][j] = 0; // Mark the column
                    else
                        col0 = 0; // First column needs to be zeroed later
                }
            }
        }

        // Step 2: Fill the inner matrix (avoiding markers for now)
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Handle the first row (based on matrix[0][0])
        if (matrix[0][0] == 0) {
            for (int j = 0; j < n; j++) matrix[0][j] = 0;
        }

        // Step 4: Handle the first column (based on col0)
        if (col0 == 0) {
            for (int i = 0; i < m; i++) matrix[i][0] = 0;
        }
    }
};