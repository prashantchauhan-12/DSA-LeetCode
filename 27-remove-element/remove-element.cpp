class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            if (nums[left] == val && nums[right] != val) {
                swap(nums[left], nums[right]);
                left++;
                right--;
            } else if (nums[right] != val) {
                left++;
            } else if (nums[right] == val) {
                right--;
            }
        }
        return left;
    }
};