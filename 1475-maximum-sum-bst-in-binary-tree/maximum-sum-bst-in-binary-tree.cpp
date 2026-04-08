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
class NodeInfo {
public:
    int minVal, maxVal, sum;
    bool isBST;

    NodeInfo(int minV, int maxV, int s, bool bst) {
        minVal = minV;
        maxVal = maxV;
        sum = s;
        isBST = bst;
    }
};

class Solution {
    int globalMaxSum = 0;

public:
    int maxSumBST(TreeNode* root) {
        helper(root);
        return globalMaxSum;
    }

private:
    NodeInfo helper(TreeNode* root) {
        // Base case: An empty tree is a BST with sum 0
        if (!root) {
            return NodeInfo(INT_MAX, INT_MIN, 0, true);
        }

        // Post-order: Get info from left and right subtrees
        NodeInfo left = helper(root->left);
        NodeInfo right = helper(root->right);

        // Check if the current subtree is a valid BST
        if (left.isBST && right.isBST && root->val > left.maxVal &&
            root->val < right.minVal) {
            int currentSum = root->val + left.sum + right.sum;
            globalMaxSum = max(globalMaxSum, currentSum);

            // Return updated info for the parent
            return NodeInfo(min(root->val, left.minVal),
                            max(root->val, right.maxVal), currentSum, true);
        }

        // If not a BST, we don't care about min/max/sum, just mark isBST as
        // false
        return NodeInfo(0, 0, 0, false);
    }
};
