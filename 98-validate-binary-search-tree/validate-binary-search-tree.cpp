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
    bool isValidBST(TreeNode* root) {
        return checkBST(root, LONG_MIN, LONG_MAX);
    }

    bool checkBST(TreeNode* root, long minVal, long maxVal) {
        if (root == NULL)
            return true;

        // If node value is outside the valid range, it's not a BST
        if (root->val <= minVal || root->val >= maxVal)
            return false;

        // Check left subtree with updated max bound
        // Check right subtree with updated min bound
        return checkBST(root->left, minVal, root->val) &&
               checkBST(root->right, root->val, maxVal);
    }
};