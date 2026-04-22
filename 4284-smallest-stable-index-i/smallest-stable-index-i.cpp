class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pmax(n, INT_MIN), smin(n, INT_MAX);
        pmax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pmax[i] = max(nums[i], pmax[i - 1]);
        }
        smin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            smin[i] = min(nums[i], smin[i + 1]);
        }

        int stable = 0;
        for (int i = 0; i < n; i++) {
            if (pmax[i] - smin[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};