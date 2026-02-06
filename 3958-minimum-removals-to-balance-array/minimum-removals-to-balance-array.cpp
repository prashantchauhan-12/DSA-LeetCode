class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1)
            return 0;

        sort(nums.begin(), nums.end());

        int max_kept = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            while (j < n && (long long)nums[j] <= (long long)nums[i] * k) {
                j++;
            }
            max_kept = max(max_kept, j - i);
        }

        return n - max_kept;
    }
};