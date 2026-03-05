class Solution {
public:
    vector<string> result;
    void f(int idx, string& temp, string& digits,
           unordered_map<char, string>& mp) {

        if (idx == digits.size()) {
            result.push_back(temp);
            return;
        }

        string word = mp[digits[idx]];
        for (int i = 0; i < word.size(); i++) {
            temp.push_back(word[i]);
            f(idx + 1, temp, digits, mp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string temp = "";
        f(0, temp, digits, mp);
        return result;
    }
};