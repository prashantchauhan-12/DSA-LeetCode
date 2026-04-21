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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        UnionFind uf(n);

        // Step 1: union given pairs
        for (int i = 0; i < pairs.size(); i++) {
            uf.unionSet(pairs[i][0], pairs[i][1]);
        }

        // Step 2: group indices by component
        unordered_map<int, vector<int>> comp;
        for (int i = 0; i < n; i++) {
            comp[uf.findSet(i)].push_back(i);
        }

        string res = s;
        // Step 3: process each component
        for (auto& it : comp) {
            vector<int> indices = it.second;

            vector<char> values;
            for (int i : indices) {
                values.push_back(s[i]);
            }

            sort(indices.begin(), indices.end());
            sort(values.begin(), values.end());

            for (int i = 0; i < indices.size(); i++) {
                res[indices[i]] = values[i];
            }
        }

        return res;
    }
};