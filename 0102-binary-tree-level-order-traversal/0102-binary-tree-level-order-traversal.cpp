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
        vector<vector<int>>result;
        if(root == NULL) return {};
        queue< TreeNode* >q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>temp;
            while(size>0){
            TreeNode *x = q.front();
            q.pop();
            temp.push_back(x->val);
            if(x->left) q.push(x->left);
            if(x->right) q.push(x->right);
            size--;
            }
           result.push_back(temp); 
        }
        return result;
    }
};