class Solution {
    static const int mod = 1e9 + 7;
    using ll = long long;

    ll power(ll x, ll y) {
        ll res = 1;
        x %= mod;
        while (y) {
            if (y & 1)
                res = res * x % mod;
            x = x * x % mod;
            y >>= 1;
        }
        return res;
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int T = sqrt(n) + 1;

        // groups[k]={l,r,v}
        vector<vector<vector<int>>> groups(T);
        for (auto q : queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];

            if (k < T) {
                groups[k].push_back(q);
            } else {
                int idx = l;
                while (idx <= r) {
                    long long temp = (1LL * nums[idx] * v);
                    temp = temp % (1000000007);
                    nums[idx] = temp;
                    idx += k;
                }
            }
        }

        vector<ll> dif(n + T);
        for (int k = 1; k < T; k++) {
            if (groups[k].empty())
                continue;

            fill(dif.begin(), dif.end(), 1);

            // apply queries
            for (auto q : groups[k]) {
                int l = q[0], r = q[1], v = q[3];
                dif[l] = dif[l] * v % mod;

                int R = l + ((r - l) / k + 1) * k;
                if (R < n) {
                    dif[R] = dif[R] * power(v, mod - 2) % mod;
                }
            }

            // propogate like prefix sum
            for (int i = k; i < n; i++) {
                dif[i] = dif[i] * dif[i - k] % mod;
            }

            // apply to nums
            for (int i = 0; i < nums.size(); i++) {
                nums[i] = 1LL * nums[i] * dif[i] % mod;
            }
        }

        int xorr = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            xorr ^= nums[i];
        }
        return xorr;
    }
};