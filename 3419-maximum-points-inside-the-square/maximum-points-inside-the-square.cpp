class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n = points.size();

        vector<pair<int, char>> v;
        for (int i = 0; i < n; i++) {
            int x = points[i][0], y = points[i][1];
            int d = max(abs(x), abs(y));

            v.push_back({d, s[i]});
        }

        sort(v.begin(), v.end());
        set<char> st;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int d = v[i].first;
            char ch = v[i].second;
            if (st.find(ch) == st.end()) {
                cnt++;
                st.insert(ch);
            } else {
                if (v[i - 1].first == v[i].first)
                    cnt--;
                break;
            }
        }
        return cnt;
    }
};