/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // Function to find path from root to given node
    bool findPath(TreeNode* root, TreeNode* node, vector<TreeNode*>& path) {
        if (root == NULL)
            return false;

        // Add current node to path
        path.push_back(root);

        // If target node is found
        if (root == node)
            return true;

        // Recur for left and right subtree
        if (findPath(root->left, node, path) ||
            findPath(root->right, node, path)) {
            return true;
        }

        // Backtrack if not found
        path.pop_back();
        return false;
    }

    // Function to find Lowest Common Ancestor
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*> pathp, pathq;

        // Find paths from root to p and q
        if (!findPath(root, p, pathp) || !findPath(root, q, pathq)) {
            return NULL;
        }

        // Compare both paths
        TreeNode* ans = NULL;
        int i = 0;
        int minSize = min(pathp.size(), pathq.size());

        while (i < minSize && pathp[i] == pathq[i]) {
            ans = pathp[i];
            i++;
        }

        return ans;
    }
};
