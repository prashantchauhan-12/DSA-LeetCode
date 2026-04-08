class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for (int i = 0; i < queries.size(); i++) {
            int li = queries[i][0], ri = queries[i][1], ki = queries[i][2],
                vi = queries[i][3];

            int idx = li;
            while (idx <= ri) {
                long long temp = nums[idx];
                temp = (temp * vi) % (1000000007);
                nums[idx] = temp;
                idx += ki;
            }
        }

        int xorr = 0;
        for (int i = 0; i < nums.size(); i++) {
            xorr ^= nums[i];
        }
        return xorr;
    }
};