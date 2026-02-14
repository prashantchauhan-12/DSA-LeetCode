class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[node] = true;
        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[node][j] && !visited[j]) {
                dfs(j, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cnt = 0;
        vector<int> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                cnt++;
                dfs(i, isConnected, visited);
            }
        }
        return cnt;
    }
};