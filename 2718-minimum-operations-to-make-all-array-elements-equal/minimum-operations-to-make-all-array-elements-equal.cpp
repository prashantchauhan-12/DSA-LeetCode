class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<long long> ps(n, 0);
        ps[0] = nums[0];
        for (int i = 1; i < n; i++) {
            ps[i] = ps[i - 1] + nums[i];
        }

        vector<long long> ans;
        for (int target : queries) {
            // i is the number of elements <= target
            int i = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

            long long left = 0, right = 0;

            // Elements to the left: nums[0...i-1]
            if (i > 0) {
                left = 1LL * target * i - ps[i - 1];
            }

            // Elements to the right: nums[i...n-1]
            if (i < n) {
                long long left_sum_to_exclude = (i > 0) ? ps[i - 1] : 0;
                long long right_sum = ps[n - 1] - left_sum_to_exclude;
                int right_count = n - i;
                right = right_sum - 1LL * right_count * target;
            }

            ans.push_back(left + right);
        }
        return ans;
    }
};