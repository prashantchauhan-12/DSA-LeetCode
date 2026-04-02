class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxLen = 0;

        for (auto num : st) {
            if (st.find(num - 1) == st.end()) {
                int len = 1;
                int cur = num;
                while (st.find(cur + 1) != st.end()) {
                    len++;
                    cur++;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};