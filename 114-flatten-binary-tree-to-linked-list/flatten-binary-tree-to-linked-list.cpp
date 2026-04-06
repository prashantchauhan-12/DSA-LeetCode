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
    // Standard pointer to keep track of the node processed last
    TreeNode* prev = NULL;

public:
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;

        // Step 1: Traverse the Right subtree first
        flatten(root->right);

        // Step 2: Traverse the Left subtree
        flatten(root->left);

        // Step 3: Process the Root
        // Set the right to the previously flattened head
        root->right = prev;
        // Set left to NULL as per linked list requirement
        root->left = NULL;

        // Update prev to the current root for the next recursive call
        prev = root;
    }
};