/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case
        if (root == NULL)
            return NULL;

        // If current node is p or q → return it
        if (root == p || root == q)
            return root;

        // Search in left and right subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If one side is NULL → return the other
        if (left == NULL)
            return right;

        if (right == NULL)
            return left;

        // If both sides are not NULL → current node is LCA
        return root;
    }
};
