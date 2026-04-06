class Solution {
public:
    // Step 1: Mark parent of each node
    void markParents(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& parent_track) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (current->left) {
                parent_track[current->left] = current;
                q.push(current->left);
            }

            if (current->right) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        // Step 1: Build parent map
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParents(root, parent_track);

        // Step 2: BFS from target
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        q.push(target);
        visited[target] = true;

        int curr_level = 0;

        while (!q.empty()) {
            int size = q.size();

            // Stop when we reach level k
            if (curr_level == k)
                break;
            curr_level++;

            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();

                // Left child
                if (current->left && !visited[current->left]) {
                    q.push(current->left);
                    visited[current->left] = true;
                }

                // Right child
                if (current->right && !visited[current->right]) {
                    q.push(current->right);
                    visited[current->right] = true;
                }

                // Parent
                if (parent_track[current] && !visited[parent_track[current]]) {
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }

        // Step 3: Collect result
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};