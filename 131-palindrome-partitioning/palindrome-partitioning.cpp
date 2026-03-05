class Solution {
public:
    bool isPalindrome(string s, int l, int r) {
        bool flag = true;
        while (l <= r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    void backTrack(int idx, vector<string>& curr,
                   vector<vector<string>>& result, string& s) {
        int n = s.size();

        if (idx == n) {
            result.push_back(curr);
        }

        for (int i = idx; i < n; i++) {
            if (isPalindrome(s, idx, i)) {
                curr.push_back(s.substr(idx, i - idx + 1));
                backTrack(i + 1, curr, result, s);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;

        backTrack(0, curr, result, s);
        return result;
    }
};