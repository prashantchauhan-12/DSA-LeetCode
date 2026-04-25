class Solution {
public:
    bool check(int mid, vector<long long>& dists, int k, int side) {
        long long perimeter = 1LL * 4 * side;
        int n = dists.size() / 2;

        for (int i = 0; i < dists.size() / 2; i++) {
            long long first = dists[i];
            long long last = first;
            int taken = 1;

            int pos = i;
            int end = i + n;

            while (taken < k) {
                auto it = lower_bound(dists.begin() + pos + 1,
                                      dists.begin() + end, last + mid);

                if (it == dists.begin() + end)
                    break;

                last = *it;
                pos = it - dists.begin();
                taken++;
            }

            // check circular gap
            if (taken == k && (first + perimeter - last) >= mid) {
                return true;
            }
        }
        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> dists;
        // Step 1: Transform 2D points to 1D Linear Distances
        for (auto& p : points) {
            long long x = p[0], y = p[1];
            if (y == 0)
                dists.push_back(x);
            else if (x == side)
                dists.push_back(side + y);
            else if (y == side)
                dists.push_back(3LL * side - x);
            else if (x == 0)
                dists.push_back(4LL * side - y);
        }

        sort(dists.begin(), dists.end());

        int n = dists.size();
        long long perimeter = 4LL * side;

        // Step 2: Handle circular by duplication
        for (int i = 0; i < n; i++) {
            dists.push_back(dists[i] + perimeter);
        }

        // Step 3: Binary Search on answer
        long long low = 1, high = 2 * 1LL * side;
        long long ans = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (check(mid, dists, k, side)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};