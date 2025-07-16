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
    int dfs(TreeNode *node, long long currSum, int targetSum, unordered_map<long long , int>&prefix){
        if(!node) return 0;
        currSum += node->val;
        int count = prefix[currSum - targetSum];
        prefix[currSum]++;

        count += dfs(node->left, currSum, targetSum, prefix);
        count += dfs(node->right, currSum, targetSum, prefix);

        prefix[currSum]--; // backtrack
        
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int>mpp;
        mpp[0] = 1;         // base case for direct match
        return dfs(root, 0 , targetSum, mpp);
    }
};