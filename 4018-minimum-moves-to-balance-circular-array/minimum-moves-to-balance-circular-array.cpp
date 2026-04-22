class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size();
        long long total_sum = 0;
        int target = -1;

        // Step 1: Find total sum and identify the ONE negative index
        for (int i = 0; i < n; i++) {
            total_sum += balance[i];
            if (balance[i] < 0) {
                target = i;
            }
        }

        // If no one is negative, 0 moves needed
        if (target == -1) return 0;
        // If total sum is negative, it's impossible
        if (total_sum < 0) return -1;

        // Step 2: Collect all positive balances and their distances to target
        vector<pair<int, int>> surplus;
        for (int i = 0; i < n; i++) {
            if (balance[i] > 0) {
                int dist = min((i - target + n) % n, (target - i + n) % n);
                surplus.push_back({dist, balance[i]});
            }
        }

        // Step 3: Sort by distance (Greedy)
        sort(surplus.begin(), surplus.end());

        long long moves = 0;
        long long debt = abs((long long)balance[target]);

        // Step 4: Pull from the closest neighbors
        for (auto& p : surplus) {
            int dist = p.first;
            int available = p.second;

            if (available >= debt) {
                moves += (debt * dist);
                debt = 0;
                break;
            } else {
                moves += ((long long)available * dist);
                debt -= available;
            }
        }

        return moves;
    }
};