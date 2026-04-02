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
    int getHeight(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        int lh = getHeight(root->left);
        int rh = getHeight(root->right);

        int diameter = lh + rh;

        return max(diameter, max(diameterOfBinaryTree(root->left),
                                 diameterOfBinaryTree(root->right)));
    }
};