class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIdx = nums[0];
        for (int i = 1; i < n - 1; i++) {
            if (i <= maxIdx) {
                maxIdx = max(maxIdx, nums[i] + i);
            }
        }

        return maxIdx >= n - 1;
    }
};