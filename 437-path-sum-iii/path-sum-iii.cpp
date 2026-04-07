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
    int count = 0;
    unordered_map<long long, int> prefixSumMap;

    void dfs(TreeNode* node, long long currentSum, int targetSum) {
        if (node == NULL)
            return;

        currentSum+=node->val;
        
        // path from root to current equal to targetSum
        if(currentSum==targetSum){
            count++;
        }

        // situation 2, a sub path ending at this node equal to targetSum
        if(prefixSumMap.find(currentSum-targetSum) != prefixSumMap.end()){
            count+=prefixSumMap[currentSum-targetSum];
        }

        prefixSumMap[currentSum]++;

        dfs(node->left,currentSum,targetSum);
        dfs(node->right,currentSum,targetSum);

        prefixSumMap[currentSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        count = 0;
        prefixSumMap.clear();
        dfs(root, 0, targetSum);
        return count;
    }
};