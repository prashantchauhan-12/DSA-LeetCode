class Solution {
public:
    int result = 0;
    void f(int idx, int count, int n, vector<int>& building,
           vector<vector<int>>& requests) {
        if (idx == requests.size()) {
            bool isAllZero = true;
            for (auto it : building) {
                if (it != 0) {
                    isAllZero = false;
                }
            }

            if (isAllZero) {
                result = max(result, count);
            }
            return;
        }

        int from = requests[idx][0];
        int to = requests[idx][1];
        // take
        building[to]++;
        building[from]--;
        f(idx + 1, count + 1, n, building, requests);

        // nottake
        building[to]--;
        building[from]++;
        f(idx + 1, count, n, building, requests);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> building(n, 0);
        f(0, 0, n, building, requests);
        return result;
    }
};