class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++) {
            vp.push_back({nums[i], i});
        }

        sort(vp.begin(), vp.end());

        vector<int> res(n);

        int i = 0;
        while (i < n) {
            int j = i;

            // form group
            while (j + 1 < n && vp[j + 1].first - vp[j].first <= limit) {
                j++;
            }

            // collect indices & values
            vector<int> indices, values;
            for (int k = i; k <= j; k++) {
                indices.push_back(vp[k].second);
                values.push_back(vp[k].first);
            }

            sort(indices.begin(), indices.end());

            // values already sorted because vp sorted

            for (int k = 0; k < indices.size(); k++) {
                res[indices[k]] = values[k];
            }

            i = j + 1;
        }

        return res;
    }
};