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
    bool check(TreeNode* root, int& currentSum, int targetSum) {
        if (root == NULL)
            return false;

        currentSum += root->val;
        if (root->left == NULL && root->right == NULL)
            if (currentSum == targetSum)
                return true;

        bool found = check(root->left, currentSum, targetSum) ||
                     check(root->right, currentSum, targetSum);

        currentSum -= root->val;
        return found;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int startSum = 0;
        return check(root, startSum, targetSum);
    }
};