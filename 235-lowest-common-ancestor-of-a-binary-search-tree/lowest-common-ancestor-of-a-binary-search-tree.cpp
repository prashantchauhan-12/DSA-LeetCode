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
        while (root != NULL) {
            // If both nodes are smaller, move left
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            // If both nodes are larger, move right
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            // If it's a split point, we've found the LCA
            else {
                return root;
            }
        }
        return NULL;
    }
};