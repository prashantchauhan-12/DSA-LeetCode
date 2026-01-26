class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        int maxi = 0;

        for (int i = 1; i < n + 1; i++) {
            if (nums[i - 1] == 1) {
                c++;
                maxi = max(c, maxi);
            } else {
                c = 0;
            }
        }
        return maxi;
    }
};