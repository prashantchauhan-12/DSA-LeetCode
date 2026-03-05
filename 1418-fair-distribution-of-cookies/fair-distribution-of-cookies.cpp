class Solution {
public:
    int result = INT_MAX;
    int n;
    void backtrack(int idx, vector<int>& children, vector<int>& cookies) {
        if (idx == n) {
            int maxi = *max_element(children.begin(), children.end());
            result = min(result, maxi);
            return;
        }

        for (int i = 0; i < children.size(); i++) {
            children[i] += cookies[idx];
            backtrack(idx + 1, children, cookies);
            children[i] -= cookies[idx];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        vector<int> children(k);
        backtrack(0, children, cookies);
        return result;
    }
};