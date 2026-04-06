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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* cur = root;

        while (cur != NULL) {
            if (cur->left == NULL) {
                // Case 1: No left child, visit and move right
                inorder.push_back(cur->val);
                cur = cur->right;
            } else {
                // Case 2: Left child exists, find the predecessor
                TreeNode* prev = cur->left;
                while (prev->right != NULL && prev->right != cur) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    // Case 2A: Create thread and move left
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    // Case 2B: Left subtree done, break thread, visit root,
                    // move right
                    prev->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return inorder;
    }
};