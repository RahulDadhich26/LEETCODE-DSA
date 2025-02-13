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
    void inorder(TreeNode* root, vector<int>&v){
        if(root == NULL) return ;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        inorder(root ,v);
        int sum = 0;
        int l = 0 ;
        int n = v.size();
        int r = n-1;
        while(l < r){
            sum += v[l] + v[r];
            if(sum == k) return true;
            else if(sum < k) l++;
            else r--;
            sum = 0;
        }
        return false;
    }
};