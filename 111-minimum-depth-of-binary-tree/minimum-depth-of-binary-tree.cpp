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
        if (!root)
            return 0;

        // If there is no left child, we must take the right path
        if (!root->left)
            return 1 + minDepth(root->right);

        // If there is no right child, we must take the left path
        if (!root->right)
            return 1 + minDepth(root->left);

        // If both exist, take the minimum of the two
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};