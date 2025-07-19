class Solution {
public:
    // Step 1: DFS/BFS helper to store parent references for each node
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track) {
        queue<TreeNode*> q;
        q.push(root);

        // BFS to map child -> parent
        while (!q.empty()) {
            TreeNode* current = q.front(); 
            q.pop();

            if (current->left) {
                parent_track[current->left] = current; // child points to parent
                q.push(current->left);
            }
            if (current->right) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }

    // Step 2: BFS from the target node to find all nodes at distance K
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track; // Node -> Parent mapping
        markParents(root, parent_track); // Preprocessing step

        unordered_map<TreeNode*, bool> visited; // To avoid revisiting nodes
        queue<TreeNode*> q;
        q.push(target); // Start BFS from the target node
        visited[target] = true;

        int curr_level = 0;

        // Classic level-order BFS traversal
        while (!q.empty()) {
            int size = q.size();
            
            // Break out if we've reached the desired distance
            if (curr_level == k) break;

            // Traverse all nodes at the current level
            while (size--) {
                TreeNode* current = q.front(); 
                q.pop();

                // Move to the left child if it exists and not visited
                if (current->left && !visited[current->left]) {
                    q.push(current->left);
                    visited[current->left] = true;
                }

                // Move to the right child if it exists and not visited
                if (current->right && !visited[current->right]) {
                    q.push(current->right);
                    visited[current->right] = true;
                }

                // Move up to the parent node if not visited
                if (parent_track[current] && !visited[parent_track[current]]) {
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }

            curr_level++; // Move one level deeper in BFS
        }

        // Collect all nodes that are exactly K distance away
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};