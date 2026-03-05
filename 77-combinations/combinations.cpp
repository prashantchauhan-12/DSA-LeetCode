class Solution {
public:
    void f(int c, int k, vector<int>& curr, vector<vector<int>>& result,
           int n) {
        if (c > n) {
            if (k == 0)
                result.push_back(curr);
            return;
        }

        // take
        if (k > 0) {
            curr.push_back(c);
            f(c + 1, k - 1, curr, result, n);
            curr.pop_back();
        }

        // nottake
        f(c + 1, k, curr, result, n);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> curr;
        f(1, k, curr, result, n);
        return result;
    }
};