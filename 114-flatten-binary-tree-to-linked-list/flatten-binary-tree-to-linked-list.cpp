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
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode* prev = cur->left;
                // Find the rightmost node in the left subtree
                while (prev->right) {
                    prev = prev->right;
                }
                // Connect the rightmost node to the current right subtree
                prev->right = cur->right;
                // Move left subtree to the right
                cur->right = cur->left;
                cur->left = NULL;
            }
            // Move to the next node in the flattened list
            cur = cur->right;
        }
    }
};