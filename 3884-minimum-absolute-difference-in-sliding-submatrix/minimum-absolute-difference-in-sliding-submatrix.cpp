class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                set<int> st;
                vector<int> temp;
                for (int a = i; a < i + k; a++) {
                    for (int b = j; b < j + k; b++) {
                        if (st.count(grid[a][b]) == 0)
                            temp.push_back(grid[a][b]);
                        st.insert(grid[a][b]);
                    }
                }
                if (temp.size() == 1) {
                    ans[i][j] = 0;
                } else {
                    sort(temp.begin(), temp.end());
                    int mini = INT_MAX;
                    
                    for (int i = 1; i < temp.size(); i++) {
                        mini = min(mini, abs(temp[i] - temp[i - 1]));
                    }

                    ans[i][j] = mini;
                }
            }
        }
        return ans;
    }
};