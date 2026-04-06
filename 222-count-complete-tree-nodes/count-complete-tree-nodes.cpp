class Solution {
public:

    // Function to count nodes
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;

        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);

        // If perfect binary tree
        if (lh == rh) {
            return (1 << lh) - 1;
        }

        // Otherwise recurse
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Find leftmost height
    int findHeightLeft(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }

    // Find rightmost height
    int findHeightRight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->right;
        }
        return height;
    }
};