class Solution {
public:
    void f(int c, int k, vector<int>& curr, vector<vector<int>>& result, int n) {
        if (k == 0) {
            result.push_back(curr);
            return;
        }
        
        if (c > n) return;

        // Choice 1: Take the current number 'c'
        curr.push_back(c);
        f(c + 1, k - 1, curr, result, n);
        
        // Backtrack: Remove 'c' before making the next choice
        curr.pop_back();

        // Choice 2: Don't take the current number 'c'
        f(c + 1, k, curr, result, n);
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> curr;
        f(1, k, curr, result, n);
        return result;
    }
};