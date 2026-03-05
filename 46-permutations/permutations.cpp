class Solution {
public:
    void f(int idx, vector<vector<int>>& result, vector<int>& nums) {
        if (idx == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            f(idx + 1, result, nums);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        f(0, result, nums);
        return result;
    }
};