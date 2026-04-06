
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* cur = root;

        while (cur != NULL) {
            if (cur->left == NULL) {
                // If no left child, visit root and move right
                preorder.push_back(cur->val);
                cur = cur->right;
            } else {
                // Find the Inorder Predecessor
                TreeNode* prev = cur->left;
                while (prev->right != NULL && prev->right != cur) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    // CASE A: Create Thread
                    prev->right = cur;
                    // PREORDER: Visit the root BEFORE moving to the left
                    // subtree
                    preorder.push_back(cur->val);
                    cur = cur->left;
                } else {
                    // CASE B: Break Thread
                    prev->right = NULL;
                    // Left subtree is already done, just move right
                    cur = cur->right;
                }
            }
        }
        return preorder;
    }
};