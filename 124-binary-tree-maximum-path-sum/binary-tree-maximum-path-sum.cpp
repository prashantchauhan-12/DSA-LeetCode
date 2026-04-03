class Solution {
public:
    int findMaxPath(TreeNode* node, int& maxi) {
        if (!node)
            return 0;

        // 1. Calculate the max path gain from left and right subtrees
        // We use max(0, ...) because if a path sum is negative,
        // it's better to just not include that branch at all.
        int leftGain = max(0, findMaxPath(node->left, maxi));
        int rightGain = max(0, findMaxPath(node->right, maxi));

        // 2. The "Split" Case: Path through current node connecting left and
        // right This is a potential candidate for the global maximum
        int currentMaxPath = node->val + leftGain + rightGain;
        maxi = max(maxi, currentMaxPath);

        // 3. The "Bridge" Case: Return the path that can be extended upwards
        // We can only pick ONE branch (left or right) to continue to the parent
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = -1e9;
        findMaxPath(root, maxi);
        return maxi;
    }
};