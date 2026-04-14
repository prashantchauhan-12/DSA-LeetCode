class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // Step 1: Count frequency of each task
        unordered_map<char, int> mp;
        for (char t : tasks) {
            mp[t]++;
        }

        // Step 2: Max heap to always pick the task with highest remaining frequency
        priority_queue<int> maxHeap;
        for (auto it : mp) {
            maxHeap.push(it.second);
        }

        int time = 0;

        // Step 3: Process tasks in cycles of size (n + 1)
        // Each cycle represents the minimum gap required between same tasks
        while (!maxHeap.empty()) {

            vector<int> temp;   // store tasks that still have remaining count after this cycle
            int cycle = n + 1;  // max distinct tasks we can schedule in one cycle
            int tasksCount = 0; // actual tasks executed in this cycle

            // Step 4: Try to fill the cycle with most frequent tasks
            for (int i = 0; i < cycle; i++) {

                if (!maxHeap.empty()) {
                    int freq = maxHeap.top();
                    maxHeap.pop();

                    // Execute this task → reduce its frequency
                    if (freq - 1 > 0) {
                        temp.push_back(freq - 1);
                    }

                    tasksCount++; // one task executed
                }
            }

            // Step 5: Push remaining tasks back into heap
            for (int remaining : temp) {
                maxHeap.push(remaining);
            }

            // Step 6: Update total time
            /*
                Case 1: Heap is empty
                → No tasks left → no need to add idle time
                → Only count actual tasks executed

                Case 2: Heap NOT empty
                → Still tasks remaining but cycle couldn't be fully filled
                → We must account for idle slots → full cycle time
            */
            if (maxHeap.empty()) {
                time += tasksCount;
            } else {
                time += cycle;
            }
        }

        return time;
    }
};