class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            // Find the last index j in nums2 where nums2[j] >= nums1[i]
            int low = i, high = nums2.size() - 1;
            int bestJ = -1;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (nums2[mid] >= nums1[i]) {
                    bestJ = mid;
                    low = mid + 1; // Try to find a further index to the right
                } else {
                    high = mid - 1;
                }
            }

            if (bestJ != -1) {
                ans = max(ans, bestJ - i);
            }
        }
        return ans;
    }
};