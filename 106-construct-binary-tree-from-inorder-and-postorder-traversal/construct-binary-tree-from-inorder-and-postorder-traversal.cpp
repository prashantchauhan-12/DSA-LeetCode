class Solution {
public:
    TreeNode* build(vector<int>& postorder, int postStart, int postEnd,
                    vector<int>& inorder, int inStart, int inEnd,
                    unordered_map<int, int>& mp) {

        if (postStart > postEnd || inStart > inEnd)
            return NULL;

        // Root is last element of postorder
        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = mp[root->val];
        int numsLeft = inRoot - inStart;

        // Build left subtree
        root->left = build(postorder, postStart, postStart + numsLeft - 1,
                           inorder, inStart, inRoot - 1, mp);

        // Build right subtree
        root->right = build(postorder, postStart + numsLeft, postEnd - 1,
                            inorder, inRoot + 1, inEnd, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return build(postorder, 0, postorder.size() - 1, inorder, 0,
                     inorder.size() - 1, mp);
    }
};