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
    // void f(TreeNode* root, int& sum, int targetSum) {

    //     // Leaf Node
    //     if (root->left == NULL && root->right == NULL) {
    //         if (targetSum == sum)
    //             return true;
    //     }
    // }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return false;

        if (root->left == NULL && root->right == NULL)
            return root->val == targetSum;

        int required = targetSum - root->val;

        return (hasPathSum(root->left, required) ||
                hasPathSum(root->right, required));
    }
};