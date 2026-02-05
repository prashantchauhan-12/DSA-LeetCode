class Solution {
public:
    bool isTrionic(vector<int>& arr) {
        int n = arr.size();

        // should have 1 point of maxima and 1 point of minima
        int cnt = 0;
        int maxI = -1, minI = -1;
        for (int i = 1; i < n - 1; i++) {
            if (arr[i - 1] == arr[i])
                return false;
            if (arr[i] == arr[i + 1])
                return false;
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                cnt++;
                maxI = i;
            } else if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
                cnt++;
                minI = i;
            }
        }

        return (cnt == 2 && maxI < minI) ? true : false;
    }
};