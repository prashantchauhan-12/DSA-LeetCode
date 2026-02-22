class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int curr = -1;

        int cnt = 1;
        int ans = 0;
        while (n > 0) {
            if (prev == -1 && n % 2 == 1) {
                prev = cnt;
            } else if (prev != -1 && n % 2 == 1) {
                curr = cnt;
                ans = max(ans, curr - prev);
                prev = curr;
            }
            n /= 2;
            cnt++;
        }
        return ans;
    }
};