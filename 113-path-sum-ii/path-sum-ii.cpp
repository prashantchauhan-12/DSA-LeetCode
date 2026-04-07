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
    void check(TreeNode* root, int& currentSum, int targetSum,
               vector<int>& temp, vector<vector<int>>& ans) {
        if (root == NULL)
            return;

        currentSum += root->val;
        temp.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (currentSum == targetSum) {
                ans.push_back(temp);
            }
        }

        check(root->left, currentSum, targetSum, temp, ans);
        check(root->right, currentSum, targetSum, temp, ans);

        currentSum -= root->val;
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        int currentSum = 0;
        vector<int> temp;
        check(root, currentSum, targetSum, temp, ans);
        return ans;
    }
};