class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        map<int, int> mp;
        int dist = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            string temp = to_string(nums[i]);
            reverse(temp.begin(), temp.end());
            int tempNum = stoi(temp);
            if (mp.find(nums[i]) != mp.end()) {
                dist = min(dist, i - mp[nums[i]]);
            }
            mp[tempNum] = i;
        }
        return dist == INT_MAX ? -1 : dist;
    }
};