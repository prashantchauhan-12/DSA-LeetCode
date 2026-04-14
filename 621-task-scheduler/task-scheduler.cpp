class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Step 1: Count frequency of each task
        unordered_map<char, int> mp;
        for (char t : tasks) {
            mp[t]++;
        }

        // Step 2: Max heap to always pick the task with highest remaining
        // frequency
        priority_queue<int> maxHeap;
        for (auto it : mp) {
            maxHeap.push(it.second);
        }

        int time = 0;
        // Step 3: Process tasks in cycles of size (n + 1)
        while (!maxHeap.empty()) {

            vector<int> temp;
            int cycle = n + 1;
            int tasksCount = 0;

            for (int i = 0; i < cycle; i++) {

                if (!maxHeap.empty()) {
                    int freq = maxHeap.top();
                    maxHeap.pop();

                    // Execute this task → reduce its frequency
                    if (freq - 1 > 0) {
                        temp.push_back(freq - 1);
                    }

                    tasksCount++;
                }
            }

            for (int remaining : temp) {
                maxHeap.push(remaining);
            }

            if (maxHeap.empty()) {
                time += tasksCount;
            } else {
                time += cycle;
            }
        }

        return time;
    }
};