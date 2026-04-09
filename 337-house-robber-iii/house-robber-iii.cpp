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
    map<TreeNode*, int> mp;
    int f(TreeNode* root) {
        if (root == NULL)
            return 0;

        if (mp.find(root) != mp.end()) {
            return mp[root];
        }

        int nottake = f(root->left) + f(root->right);

        int take = root->val;
        if (root->left) {
            take += f(root->left->left);
            take += f(root->left->right);
        }

        if (root->right) {
            take += f(root->right->left);
            take += f(root->right->right);
        }

        return mp[root] = max(take, nottake);
    }

    int rob(TreeNode* root) {
        mp.clear();
        return f(root);
    }
};