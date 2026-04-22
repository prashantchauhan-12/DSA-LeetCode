class Solution {
public:
    static bool mycmp(vector<int> a, vector<int> b) { return a[2] > b[2]; }
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<vector<int>> visited(n, vector<int>(m, 0));
        sort(sources.begin(), sources.end(), mycmp);

        int cnt = n * m;
        queue<vector<int>> q;
        for (auto vec : sources) {
            grid[vec[0]][vec[1]] = vec[2];
            visited[vec[0]][vec[1]] = 1;
            q.push(vec);
            cnt--;
        }

        while (!q.empty()) {
            int sz = q.size();
            if (cnt == 0)
                break;

            for (int i = 0; i < sz; i++) {
                vector<int> current = q.front();
                q.pop();

                int x = current[0];
                int y = current[1];
                int color = current[2];

                for (auto dir : dirs) {
                    int ni = x + dir.first;
                    int nj = y + dir.second;

                    if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                        !visited[ni][nj]) {
                        visited[ni][nj] = 1;
                        grid[ni][nj] = color;
                        q.push({ni, nj, color});
                        cnt--;
                    }
                }
            }
        }
        return grid;
    }
};