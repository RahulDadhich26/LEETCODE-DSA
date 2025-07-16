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
    vector<vector<int>>result;

    void dfs(TreeNode* root, int targetsum , vector<int>&Path){
        if(!root) return;

        Path.push_back(root->val);
        targetsum -= root->val;

        if(!root->left && !root->right && targetsum == 0){
            result.push_back(Path);
        }
        else{
            dfs(root->left, targetsum, Path);
            dfs(root->right, targetsum, Path);
        }
        Path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        dfs(root, targetSum,path);
      
        return result;
    }
};