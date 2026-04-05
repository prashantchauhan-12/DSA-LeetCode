class Solution {
public:
    int maxSum = INT_MIN;

    int dfs(TreeNode* node) {
        if (node == NULL)
            return 0;

        // Ignore negative contributions
        int left = max(0, dfs(node->left));
        int right = max(0, dfs(node->right));

        // Update global maximum (path passing through this node)
        maxSum = max(maxSum, left + right + node->val);

        // Return one side path (for parent use)
        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};