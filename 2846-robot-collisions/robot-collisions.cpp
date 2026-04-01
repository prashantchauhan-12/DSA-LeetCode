class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        map<int, int> mp;
        for (int i = 1; i <= positions.size(); i++) {
            mp[positions[i - 1]] = i - 1;
        }

        sort(positions.begin(), positions.end());
        stack<vector<int>> st;

        for (int i = 0; i < positions.size(); i++) {
            int idx = mp[positions[i]];
            int dir = directions[idx];
            int health = healths[idx];

            if (st.empty()) {
                st.push({idx, dir, health});
            } else {

                int idxp = st.top()[0];
                int dirp = st.top()[1];
                int healthp = st.top()[2];

                if ((dirp == 'R' && dir == 'L')) {
                    bool current_destroyed = false;
                    while (!st.empty() && st.top()[1] == 'R' && dir == 'L' &&
                           !current_destroyed) {

                        int current_idxp = st.top()[0];
                        int current_dirp = st.top()[1];
                        int current_healthp = st.top()[2];

                        if (current_healthp == health) {
                            st.pop();
                            current_destroyed = true;
                        } else if (current_healthp > health) {
                            st.pop();
                            st.push({current_idxp, current_dirp,
                                     current_healthp - 1});
                            current_destroyed = true;
                        } else { // current_healthp < health
                            st.pop();
                            health -= 1;
                        }
                    }

                    if (!current_destroyed) {
                        st.push({idx, dir, health});
                    }
                } else {
                    st.push({idx, dir, health});
                }
            }
        }

        if (st.empty())
            return {};

        vector<int> ans(positions.size(), 0);
        while (st.empty() == false) {
            int idxp = st.top()[0];
            int dirp = st.top()[1];
            int healthp = st.top()[2];

            ans[idxp] = healthp;
            st.pop();
        }
        vector<int> final_survivors;
        for (int h : ans) {
            if (h > 0) {
                final_survivors.push_back(h);
            }
        }
        return final_survivors;
    }
};