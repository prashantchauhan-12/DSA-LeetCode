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
        if (root == NULL)
            return;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();

            // Push right child first so it stays at the bottom
            if (cur->right)
                st.push(cur->right);
            // Push left child second so it is processed next
            if (cur->left)
                st.push(cur->left);

            // Re-assign pointers
            if (!st.empty()) {
                // The current node's right should point to the next node in
                // Pre-order
                cur->right = st.top();
            }
            // Always set the left child to NULL
            cur->left = NULL;
        }
    }
};