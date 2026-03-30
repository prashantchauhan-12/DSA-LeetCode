class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<vector<int>> sortedTasks;
        for (int i = 0; i < n; i++) {
            sortedTasks.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(sortedTasks.begin(), sortedTasks.end());

        vector<int> result;
        long long curr_time = 0;
        int idx = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        while (idx < n || !pq.empty()) {
            // 1. if cpu is idle
            if (pq.empty() && idx < n && curr_time < sortedTasks[idx][0]) {
                curr_time = sortedTasks[idx][0];
            }

            // 2. push all task arrived by curr_time
            while (idx < n && sortedTasks[idx][0] <= curr_time) {
                pq.push({sortedTasks[idx][1], sortedTasks[idx][2]});
                idx++;
            }

            pair<int, int> current = pq.top();
            pq.pop();

            int proc_time = current.first;
            int original_idx = current.second;

            curr_time += proc_time;
            result.push_back(original_idx);
        }
        return result;
    }
};