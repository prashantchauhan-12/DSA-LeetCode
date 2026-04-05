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
    void f(TreeNode* root, int x, int y, map<int, vector<pair<int, int>>>& mp) {
        if (root == NULL)
            return;

        mp[x].push_back({y, root->val});
        f(root->left, x - 1, y + 1, mp);
        f(root->right, x + 1, y + 1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, vector<pair<int, int>>> mp;
        f(root, 0, 0, mp);

        for (auto& it : mp) {
            sort(it.second.begin(), it.second.end());
        }

        for (auto it : mp) {
            vector<int> temp;
            for (auto el : it.second) {
                temp.push_back(el.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};