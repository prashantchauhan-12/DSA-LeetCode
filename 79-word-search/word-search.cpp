class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    int n, m;

    bool dfs(int x, int y, int idx, vector<vector<char>>& board, string& word) {
        if (idx == word.size()) {
            return true;
        }

        char temp = board[x][y];
        board[x][y] = '#';

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                board[nx][ny] == word[idx]) {
                if (dfs(nx, ny, idx + 1, board, word))
                    return true;
            }
        }

        board[x][y] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, 1, board, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};