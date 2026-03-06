class Solution {
public:
    int n;
    vector<int> result;
    int minSum = INT_MAX;

    void solve(int sum, vector<int>& perm, vector<bool>& visited,
               vector<int>& nums) {
        if (sum >= minSum)
            return;

        if (perm.size() == n) {
            sum += abs(perm.back() - nums[perm[0]]);
            if (sum < minSum) {
                minSum = sum;
                result = perm;
            }
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                perm.push_back(i);
                visited[i] = true;
                solve(sum + abs(perm[perm.size() - 2] -
                                nums[perm[perm.size() - 1]]),
                      perm, visited, nums);
                visited[i] = false;
                perm.pop_back();
            }
        }
    }

    vector<int> findPermutation(vector<int>& nums) {
        n = nums.size();
        vector<bool> visited(n, false);
        vector<int> perm = {0};
        visited[0] = true;

        solve(0, perm, visited, nums);
        return result;
    }
};