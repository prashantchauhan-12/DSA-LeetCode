class Solution {
public:
    typedef pair<int, int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> count_map;
        for (int n : nums) {
            count_map[n] += 1;
        }

        priority_queue<p, vector<p>, greater<p>> pq;
        unordered_map<int, int> mp;
        for (int i : nums) {
            mp[i]++;
        }

        for (auto it : mp) {
            pq.push({it.second, it.first});

            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};