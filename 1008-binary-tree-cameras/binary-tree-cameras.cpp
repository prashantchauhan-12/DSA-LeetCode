class Solution {
public:
    int cameras = 0;

    int dfs(TreeNode* root) {
        if (root == NULL) return 2; // null is covered

        int left = dfs(root->left);
        int right = dfs(root->right);

        // If any child needs camera → place here
        if (left == 0 || right == 0) {
            cameras++;
            return 1;
        }

        // If any child has camera → I'm covered
        if (left == 1 || right == 1) {
            return 2;
        }

        // Otherwise → I need camera
        return 0;
    }

    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) cameras++; // root case
        return cameras;
    }
};