/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // Helper function to count paths starting from a specific node
    int countFrom(TreeNode* node, long long currentSum, int targetSum) {
        if (!node)
            return 0;

        int paths = 0;
        currentSum += node->val;

        if (currentSum == targetSum) {
            paths = 1;
        }

        // Continue checking children to see if further nodes sum back to target
        // (important if there are 0 or negative values)
        return paths + countFrom(node->left, currentSum, targetSum) +
               countFrom(node->right, currentSum, targetSum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;

        // 1. Count paths starting at the CURRENT root
        int pathsFromRoot = countFrom(root, 0, targetSum);

        // 2. Recursively find paths in the left and right subtrees
        int pathsInLeft = pathSum(root->left, targetSum);
        int pathsInRight = pathSum(root->right, targetSum);

        return pathsFromRoot + pathsInLeft + pathsInRight;
    }
};