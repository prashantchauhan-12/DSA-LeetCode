class Solution {
public:
    long long f(int speed, vector<int>& piles) {
        long long t = 0;
        for (auto banana : piles) {
            t += ceil(((1.0) * banana) / speed);
        }
        return t;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            long long totalHours = f(mid, piles);
            if (totalHours <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};