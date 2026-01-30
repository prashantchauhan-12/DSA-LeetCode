class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0, right = 0;
        map<int, int> mp;
        int len = 0;
        int maxf = 0;

        while (right < n) {
            mp[s[right]]++;
            maxf = max(maxf, mp[s[right]]);

            while ((right - left + 1 - maxf) > k) {
                mp[s[left]]--;
                left++;
            }

            if (right - left + 1 - maxf <= k) {
                len = max(len, right - left + 1);
            }
            right++;
        }
        return len;
    }
};