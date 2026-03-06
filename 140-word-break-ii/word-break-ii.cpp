class Solution {
public:
    vector<string> result;
    int n;
    void backtrack(int idx, string curr, string& s,
                   unordered_map<string, int>& mp) {
        // Base Case: If we reaced the end of the string
        if (idx == n) {
            result.push_back(curr);
            return;
        }

        // Try every possible substring starting from idx
        for (int i = idx; i < n; i++) {
            string word = s.substr(idx, i - idx + 1);

            // Check if the word is in the dictionary
            if (mp.count(word)) {
                string nextCurr = curr.empty() ? word : curr + " " + word;
                backtrack(i + 1, nextCurr, s, mp);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();

        unordered_map<string, int> mp;
        for (auto str : wordDict) {
            mp[str]++;
        }

        backtrack(0, "", s, mp);
        return result;
    }
};