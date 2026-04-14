#include <map>
#include <vector>

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        // Step 1: Basic validation
        if (n % groupSize != 0) {
            return false;
        }

        // Step 2: Count frequencies and sort
        map<int, int> freq;
        for (auto val : hand) {
            freq[val]++;
        }

        // Step 3: Greedy Grouping
        auto it = freq.begin();
        while (it != freq.end()) {
            // If the current card has already been fully used in previous
            // groups, skip it
            if (it->second == 0) {
                ++it;
                continue;
            }

            int start = it->first;
            int count = it->second;

            for (int i = 0; i < groupSize; i++) {
                int nextCard = start + i;
                if (freq[nextCard] < count) {
                    return false;
                }
                freq[nextCard] -= count;
            }

            ++it;
        }
        return true;
    }
};