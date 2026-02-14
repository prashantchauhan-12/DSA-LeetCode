class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();      // Rows
        int m = mat[0].size();   // Columns
        int low = 0, high = m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // 1. Find the index of the maximum element in the current column (mid)
            int maxRow = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            // 2. Check left and right neighbors
            // Treat out-of-bounds as -1
            int leftNeighbor = (mid > 0) ? mat[maxRow][mid - 1] : -1;
            int rightNeighbor = (mid < m - 1) ? mat[maxRow][mid + 1] : -1;

            if (mat[maxRow][mid] > leftNeighbor && mat[maxRow][mid] > rightNeighbor) {
                // Found a peak!
                return {maxRow, mid};
            } else if (rightNeighbor > mat[maxRow][mid]) {
                // If the right neighbor is bigger, move right
                low = mid + 1;
            } else {
                // Otherwise, move left
                high = mid - 1;
            }
        }
        return {-1, -1};
    }
};