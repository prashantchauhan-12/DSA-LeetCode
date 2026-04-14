class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for (char t : tasks) {
            mp[t]++;
        }

        priority_queue<int> maxHeap;
        for (auto it : mp) {
            maxHeap.push(it.second);
        }

        int time = 0;
        while (!maxHeap.empty()) {
            vector<int> temp;
            int cycle = n + 1;
            int tasksCount = 0;

            // Try to fill the cycle with the most frequent tasks
            for (int i = 0; i < cycle; i++) {
                if (!maxHeap.empty()) {
                    temp.push_back(maxHeap.top() - 1);
                    maxHeap.pop();
                    tasksCount++;
                }
            }

            // Put tasks with remaining frequency back into the heap
            for (int remaining : temp) {
                if (remaining > 0)
                    maxHeap.push(remaining);
            }

            // If heap is empty, we only add the actual tasks executed
            // Otherwise, we add the full cycle length (tasks + idle)
            time += maxHeap.empty() ? tasksCount : cycle;
        }

        return time;
    }
};