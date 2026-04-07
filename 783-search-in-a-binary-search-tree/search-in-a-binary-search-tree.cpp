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
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base Case: We hit a null node or found the value
        if (root == NULL || root->val == val)
            return root;

        // If the target is smaller, search the left subtree
        if (root->val > val) {
            return searchBST(root->left, val); // Added 'return'
        } 
        // If the target is larger, search the right subtree
        else {
            return searchBST(root->right, val); // Added 'return'
        }
    }
};