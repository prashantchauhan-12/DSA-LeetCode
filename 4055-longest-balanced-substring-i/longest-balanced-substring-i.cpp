class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();

        int ans = 0;
        for (int i = 0; i < n; i++) {
            map<int, int> mp;
            for (int j = i; j < n; j++) {
                mp[s[j]]++;

                int firstCount = mp.begin()->second;
                bool balanced = true;
                for (auto const& [key, count] : mp) {
                    if (count != firstCount) {
                        balanced = false;
                        break;
                    }
                }

                if (balanced) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};