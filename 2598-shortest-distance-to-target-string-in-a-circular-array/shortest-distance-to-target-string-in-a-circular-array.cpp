class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = n + 1;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int dist1 = abs(i - startIndex);
                int dist2 = n - dist1;

                ans = min(dist1, min(ans, dist2));
            }
        }
        return ans == n + 1 ? -1 : ans;
    }
};