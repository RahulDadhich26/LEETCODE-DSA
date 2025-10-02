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
    int maxsum = INT_MIN;
    int dfs(TreeNode* node){
        if(!node) return 0;
        int leftgain = max(0, dfs(node->left));
        int rightgain = max(0, dfs(node->right));
        
        int pricenewPath = node->val + leftgain + rightgain;
        maxsum = max(maxsum , pricenewPath);

        return node->val + max(leftgain,rightgain);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxsum;
    }
};