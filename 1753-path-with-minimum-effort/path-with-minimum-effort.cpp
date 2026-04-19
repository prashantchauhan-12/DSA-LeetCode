class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();

        vector<vector<int>> effort(n, vector<int>(m, 1e9));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        // {effort,x,y}

        effort[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            int currEffort = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();

            if (x == n - 1 && y == m - 1) {
                return currEffort;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int nextEffort =
                        max(currEffort, abs(heights[nx][ny] - heights[x][y]));
                    if (nextEffort < effort[nx][ny]) {
                        effort[nx][ny] = nextEffort;
                        pq.push({nextEffort, nx, ny});
                    }
                }
            }
        }
        return -1;
    }
};