class Solution {
public:
    string result = "";
    void backtrack(int idx, string ans, set<string>& st) {
        if (idx == ans.size()) {
            if (st.find(ans) == st.end()) {
                result = ans;
            }
            return;
        }

        // nottake
        backtrack(idx + 1, ans, st);

        // take
        ans[idx] = '1';
        backtrack(idx + 1, ans, st);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        set<string> st;
        for (auto it : nums) {
            st.insert(it);
        }

        string ans = "";
        for (int i = 0; i < nums.size(); i++) {
            ans += "0";
        }

        backtrack(0, ans, st);
        return result;
    }
};