class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        // store all indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;
        for (int idx : queries) {
            vector<int>& v = mp[nums[idx]];

            // only one occurrence
            if (v.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int pos = lower_bound(v.begin(), v.end(), idx) - v.begin();
            int m = v.size();

            int next = v[(pos + 1) % m];
            int prev = v[(pos - 1 + m) % m];

            int d1 = abs(idx - next);
            int d2 = abs(idx - prev);

            int minDist = min({min(d1, n - d1), min(d2, n - d2)});

            ans.push_back(minDist);
        }

        return ans;
    }
};