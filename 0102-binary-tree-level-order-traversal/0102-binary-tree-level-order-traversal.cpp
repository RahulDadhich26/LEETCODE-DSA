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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;  // Add this line
            queue<TreeNode*> q;
            q.push(root);

            while(!q.empty()) {
                vector<int> v;
                int size = q.size();
    
    for(int i = 0; i < size; i++) {
        TreeNode* value = q.front();
        q.pop();
        v.push_back(value->val);
        
        // ADD THIS: Push children to queue for next level
        if(value->left != nullptr) {
            q.push(value->left);
        }
        if(value->right != nullptr) {
            q.push(value->right);
        }
    }
    ans.push_back(v);
}
return ans;
    }
};