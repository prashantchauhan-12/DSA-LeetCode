class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int left = 0, right = 0;
        map<int, int> mp;
        int len = 0;
        while (right < n) {
            mp[s[right]]++;

            while (mp[s[right]] >= 2) {
                mp[s[left]]--;
                left++;
            }

            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};