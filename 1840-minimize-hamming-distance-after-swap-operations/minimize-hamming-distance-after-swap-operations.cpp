class UnionFind {
public:
    vector<int> parent, sz;

    UnionFind(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int findSet(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = findSet(parent[u]);
    }

    void unionSet(int u, int v) {
        int x = findSet(u);
        int y = findSet(v);

        if (x == y)
            return;

        if (sz[x] > sz[y]) {
            parent[y] = x;
            sz[x] += sz[y];
        } else {
            parent[x] = y;
            sz[y] += sz[x];
        }
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {

        int n = source.size();
        UnionFind uf(n);

        for (auto& e : allowedSwaps) {
            uf.unionSet(e[0], e[1]);
        }

        // Group indices by component
        unordered_map<int, vector<int>> comp;
        for (int i = 0; i < n; i++) {
            comp[uf.findSet(i)].push_back(i);
        }

        int ans = 0;

        for (auto& it : comp) {
            auto& indices = it.second;

            unordered_map<int, int> freq;

            // Count source values
            for (int idx : indices) {
                freq[source[idx]]++;
            }

            // Match with target
            for (int idx : indices) {
                if (freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    ans++;
                }
            }
        }

        return ans;
    }
};