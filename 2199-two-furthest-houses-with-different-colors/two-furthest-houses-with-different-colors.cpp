class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int res = 0;

        // Scenario 1: Compare everything with the first element from the end
        for (int j = n - 1; j >= 0; --j) {
            if (colors[j] != colors[0]) {
                res = max(res, j); // distance is (j - 0)
                break;
            }
        }

        // Scenario 2: Compare everything with the last element from the start
        for (int i = 0; i < n; ++i) {
            if (colors[i] != colors[n - 1]) {
                res = max(res, n - 1 - i);
                break;
            }
        }

        return res;
    }
};