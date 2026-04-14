

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // We want the element that would be at index (n - k) if sorted
        int targetIndex = nums.size() - k;

        nth_element(nums.begin(), nums.begin() + targetIndex, nums.end());

        return nums[targetIndex];
    }
};