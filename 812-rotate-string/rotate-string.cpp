class Solution {
public:
    bool rotateString(string s, string goal) {
        s = s + s;
        bool found = false;

        int n = s.size();
        int m = goal.size();

        if ((n / 2) != m) {
            return false;
        }

        for (int i = 0; i < n - m + 1; i++) {
            int j;
            for (j = 0; j < m; j++) {
                if (s[i + j] != goal[j]) {
                    break;
                }
            }
            if (j == m) {
                found = true;
                break;
            }
        }
        return found;
    }
};