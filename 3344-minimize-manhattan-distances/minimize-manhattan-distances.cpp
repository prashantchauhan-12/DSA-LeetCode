#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2)
            return 0;

        vector<int> add(n), diff(n);

        for (int i = 0; i < n; i++) {
            add[i] = points[i][0] + points[i][1];
            diff[i] = points[i][0] - points[i][1];
        }

        vector<int> s_add = add, s_diff = diff;
        sort(s_add.begin(), s_add.end());
        sort(s_diff.begin(), s_diff.end());

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            
            int max_add =
                (add[i] == s_add[n - 1] ? s_add[n - 2] : s_add[n - 1]);
            int min_add = (add[i] == s_add[0] ? s_add[1] : s_add[0]);

            int max_diff =
                (diff[i] == s_diff[n - 1] ? s_diff[n - 2] : s_diff[n - 1]);
            int min_diff = (diff[i] == s_diff[0] ? s_diff[1] : s_diff[0]);

            int curr = max(max_add - min_add, max_diff - min_diff);
            ans = min(ans, curr);
        }

        return ans;
    }
};