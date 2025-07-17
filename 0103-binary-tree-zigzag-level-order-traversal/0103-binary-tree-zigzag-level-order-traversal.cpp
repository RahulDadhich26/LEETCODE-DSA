/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level(levelSize);

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front(); q.pop();

                // Insert at correct position based on direction
                int index = leftToRight ? i : (levelSize - 1 - i);
                level[index] = node->val;

                // Push child nodes into the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Flip direction for next level
            leftToRight = !leftToRight;
            result.push_back(level);
        }

        return result;
    }
};