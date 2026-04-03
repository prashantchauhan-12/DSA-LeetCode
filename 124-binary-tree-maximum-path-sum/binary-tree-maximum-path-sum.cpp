class Solution {
public:

    // Get max path starting from this node (one direction only)
    int getPathSum(TreeNode* root) {
        if (!root) return 0;

        int left = max(0, getPathSum(root->left));
        int right = max(0, getPathSum(root->right));

        return root->val + max(left, right);
    }

    // Try every node as root of path
    int solve(TreeNode* root) {
        if (!root) return INT_MIN;

        // path passing through this node
        int left = max(0, getPathSum(root->left));
        int right = max(0, getPathSum(root->right));
        int throughRoot = root->val + left + right;

        // check in left and right subtree
        int leftAns = solve(root->left);
        int rightAns = solve(root->right);

        return max({throughRoot, leftAns, rightAns});
    }

    int maxPathSum(TreeNode* root) {
        return solve(root);
    }
};