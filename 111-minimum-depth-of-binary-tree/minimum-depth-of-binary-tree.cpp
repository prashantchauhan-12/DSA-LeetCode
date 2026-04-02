/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        // if no left child
        if (!root->left)
            return 1 + minDepth(root->right);
        // if right child
        if (!root->right)
            return 1 + minDepth(root->left);

        // if both child present
        return 1 + min(minDepth(root->right), minDepth(root->left));
    }
};