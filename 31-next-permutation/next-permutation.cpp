class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int breakp = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                breakp = i;
                break;
            }
        }

        if (breakp == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            for (int i = n - 1; i > breakp; i--) {
                if (nums[i] > nums[breakp]) {
                    swap(nums[i], nums[breakp]);
                    break;
                }
            }
            reverse(nums.begin() + breakp + 1, nums.end());
        }
    }
};