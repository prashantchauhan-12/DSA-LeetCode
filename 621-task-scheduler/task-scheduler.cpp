class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char c : tasks)
            freq[c - 'A']++;

        sort(freq.begin(), freq.end());

        int maxf = freq[25];
        int time = (maxf - 1) * (n + 1);
        time++;

        for (int i = 24; i >= 0; i--) {
            if (freq[i] == maxf)
                time++;
            else
                break;
        }

        return max((int)tasks.size(), time);
    }
};