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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // If the tree is empty, nothing to delete
        if (root == NULL) {
            return NULL;
        }

        // If the root itself is the node to be deleted,
        // call helper to get the new root of the tree
        if (root->val == key) {
            return helper(root);
        }

        // 'dummy' keeps track of the original root to return at the end
        TreeNode* dummy = root;

        while (root != NULL) {
            if (root->val > key) {
                // If the target is in the left subtree, check the left child
                if (root->left != NULL && root->left->val == key) {
                    // Node found! Reconnect parent's left to the helper's result
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                // If the target is in the right subtree, check the right child
                if (root->right != NULL && root->right->val == key) {
                    // Node found! Reconnect parent's right to the helper's result
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }

    /* Helper function to "stitch" the tree back together after a node is
       removed. It connects the deleted node's right subtree to the rightmost
       point of its left subtree.
    */
    TreeNode* helper(TreeNode* root) {
        // If left child is null, just return the right subtree
        if (root->left == NULL) {
            return root->right;
        }
        // If right child is null, just return the left subtree
        else if (root->right == NULL) {
            return root->left;
        }

        // If both children exist:
        TreeNode* rightChild = root->right;
        // Find the rightmost node in the left subtree (the largest value
        // smaller than 'root')
        TreeNode* lastRight = findLastRight(root->left);
        // Attach the original right subtree to that rightmost node
        lastRight->right = rightChild;

        // Return the left child as the new head of this subtree
        return root->left;
    }

    // Helper to find the rightmost node in a subtree (used to find the
    // attachment point)
    TreeNode* findLastRight(TreeNode* root) {
        if (root->right == NULL) {
            return root;
        }
        return findLastRight(root->right);
    }
};