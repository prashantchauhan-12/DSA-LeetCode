class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // Step 1: Count frequency of each task (A–Z)
        vector<int> freq(26, 0);
        for (char c : tasks)
            freq[c - 'A']++;

        // Step 2: Sort frequencies to get the maximum frequency at the end
        sort(freq.begin(), freq.end());

        // Step 3: Get the maximum frequency
        int maxf = freq[25];

        /*
            Core idea:
            We arrange the most frequent task first.

            Suppose maxf = 3, n = 2:
            A _ _ A _ _ A

            There are (maxf - 1) gaps → each gap size = n
            So total structure = (maxf - 1) * (n + 1)
        */
        int time = (maxf - 1) * (n + 1);

        /*
            Now handle the LAST block:
            If multiple tasks have same max frequency,
            they all occupy the last block.

            Example:
            A A A
            B B B

            Last block = A B → so we add count of such tasks
        */
        time++; // for the first max frequency task

        // Count how many tasks have same max frequency
        for (int i = 24; i >= 0; i--) {
            if (freq[i] == maxf)
                time++;
            else
                break;
        }

        /*
            Final answer:
            - Either we follow the structured schedule (with idle slots)
            - Or we have enough tasks to fill all idle gaps

            So take max:
        */
        return max((int)tasks.size(), time);
    }
};