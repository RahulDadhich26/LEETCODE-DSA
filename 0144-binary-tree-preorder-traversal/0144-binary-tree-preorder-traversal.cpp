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
    vector<int> preorderTraversal(TreeNode* root) {
        stack <TreeNode*> s;
        vector <int> result;
        
        if (root == nullptr) {
            return result; 
        }
        
        s.push(root); 
        
        while (!s.empty()) {
            TreeNode* current = s.top();
            s.pop();
            
            result.push_back(current->val); 
            
            if (current->right != nullptr) {
                s.push(current->right); 
            }
            
            if (current->left != nullptr) {
                s.push(current->left); 
            }
        }
        
        return result; 
    }
};