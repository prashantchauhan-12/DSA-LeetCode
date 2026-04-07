class Solution {
public:
    int count = 0;
    unordered_map<long long, int> prefixSumMap;

    void dfs(TreeNode* node, long long currentSum, int targetSum) {
        if (!node) return;

        // Current prefix sum from root to this node
        currentSum += node->val;

        // Situation 1: The path from root to current node equals targetSum
        if (currentSum == targetSum) {
            count++;
        }

        // Situation 2: A sub-path ending at this node equals targetSum
        // We check if (currentSum - targetSum) exists in our history
        if (prefixSumMap.find(currentSum - targetSum) != prefixSumMap.end()) {
            count += prefixSumMap[currentSum - targetSum];
        }

        // Add currentSum to map before going deeper
        prefixSumMap[currentSum]++;

        // Recurse
        dfs(node->left, currentSum, targetSum);
        dfs(node->right, currentSum, targetSum);

        // BACKTRACK: Remove the currentSum so it's not used by other branches
        prefixSumMap[currentSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        count = 0;
        prefixSumMap.clear();
        dfs(root, 0, targetSum);
        return count;
    }
};