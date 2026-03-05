class Solution {
public:
    void backTrack(int idx, vector<int>& curr, vector<int>& nums,
                   vector<vector<int>>& result) {
        int n = nums.size();
        if (curr.size() > 1) {
            result.push_back(curr);
        }

        unordered_set<int>st;
        for (int i = idx; i < n; i++) {
            if ((curr.size() == 0 || curr.back() <= nums[i]) && st.find(nums[i])==st.end()) {
                st.insert(nums[i]);
                curr.push_back(nums[i]);
                backTrack(i + 1, curr, nums, result);
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        int n = nums.size();
        backTrack(0, curr, nums, result);
        return result;
    }
};