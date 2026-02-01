class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        int minLen = INT_MAX;

        map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[t[i]]++;
        }

        int left = 0, right = 0;
        int cnt = 0, sIndex = -1;
        while (right < m) {
            if (mp[s[right]] > 0) {
                cnt++;
            }
            mp[s[right]]--;

            // when window is valid
            while (cnt == n) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    sIndex = left;
                }
                // Try shriek from the left;
                mp[s[left]]++;
                if (mp[s[left]] > 0)
                    cnt--;
                left++;
            }
            right++;
        }

        return (sIndex == -1) ? "" : s.substr(sIndex, minLen);
    }
};