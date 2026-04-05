class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        // Case 1: both null → symmetric
        if (left == NULL && right == NULL)
            return true;

        // Case 2: one null → not symmetric
        if (left == NULL || right == NULL)
            return false;

        // Case 3: values must match
        if (left->val != right->val)
            return false;

        // Case 4: check mirror structure
        return isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;

        return isMirror(root->left, root->right);
    }
};