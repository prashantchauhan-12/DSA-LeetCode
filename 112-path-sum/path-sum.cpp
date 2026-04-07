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
    bool check(TreeNode* root, int& startSum, int targetSum) {
        if (root == NULL)
            return false;

        startSum += root->val;

        if (root->left == NULL && root->right == NULL) {
            if (targetSum == startSum)
                return true;
        }

        bool found = check(root->left, startSum, targetSum) ||
                     check(root->right, startSum, targetSum);

        startSum -= root->val;

        return found;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int startSum = 0;
        return check(root, startSum, targetSum);
    }
};