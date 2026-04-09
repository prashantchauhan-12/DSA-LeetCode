class Solution {
public:
    vector<long long> dp;
    long long f(int i, vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        if (i >= n) {
            return 0;
        }

        if (dp[i] != -1)
            return dp[i];

        long long nottake = f(i + 1, nums, colors);

        long long take = nums[i];
        if (i <= n - 2 && colors[i] == colors[i + 1]) {
            take += f(i + 2, nums, colors);
        } else {
            take += f(i + 1, nums, colors);
        }

        return dp[i] = max(take, nottake);
    }

    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        dp.resize(n, -1);
        return f(0, nums, colors);
    }
};