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
    void inorder(TreeNode* root, vector<int>& vals) {
    if(!root) return;
    inorder(root->left, vals);
    vals.push_back(root->val);
    inorder(root->right, vals);
    }

    int getMinimumDifference(TreeNode* root) {
    vector<int> vals;
    inorder(root, vals);
    int minDiff = INT_MAX;
    for(int i = 1; i < vals.size(); i++)
        minDiff = min(minDiff, vals[i] - vals[i-1]);
    return minDiff;
    }
};