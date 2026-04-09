class Solution {
public:
    bool f(int mid, vector<int>& nums, int k) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= mid) {
                cnt++;
                i++; // skip adjcent;
            }
        }
        return cnt >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        int ans = high;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (f(mid, nums, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};