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
        for (auto allowedSwap : allowedSwaps) {
            uf.unionSet(allowedSwap[0], allowedSwap[1]);
        }

        unordered_map<int, vector<int>> components;
        for (int i = 0; i < n; i++) {
            components[uf.findSet(i)].push_back(i);
        }

        int ans = 0;
        for (auto component : components) {
            vector<int> indices = component.second;
            unordered_map<int, int> mp;
            for (int idx : indices) {
                mp[source[idx]]++;
            }

            for (int idx : indices) {
                if (mp[target[idx]] > 0) {
                    mp[target[idx]]--;
                } else {
                    ans++;
                }
            }
        }
        return ans;
    }
};