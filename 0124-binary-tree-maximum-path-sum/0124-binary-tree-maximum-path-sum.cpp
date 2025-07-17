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

    int maxSum(TreeNode* Node){
        if(Node == NULL) return 0 ;

        // recursively call left and right, ignore negatives
        int leftGain = max(0, maxSum(Node->left));
        int rightGain = max(0, maxSum(Node->right));

        // V- shaped thourgh current node

        int currentPath = Node->val + leftGain + rightGain;

        maxsum = max(maxsum, currentPath);

        return Node->val + max(leftGain, rightGain);
    }
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return maxsum;
    }
};