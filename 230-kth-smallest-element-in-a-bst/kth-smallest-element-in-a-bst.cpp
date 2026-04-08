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
    int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr || !st.empty()) {
        // 1. Reach the leftmost node of the current subtree
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }

        // 2. Process the node (this is the "In-order" visit)
        curr = st.top();
        st.pop();
        
        if (--k == 0) return curr->val;

        // 3. Move to the right subtree
        curr = curr->right;
    }

    return -1; // Should not be reached if k is valid
}
};