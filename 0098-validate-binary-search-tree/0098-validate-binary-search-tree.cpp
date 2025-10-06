class Solution {
public:
    long long prev = LLONG_MIN;

    bool inorder(TreeNode* root) {
        
        if(!root) return true;

        if(!inorder(root->left)) return false;

        if(root->val <= prev) return false;

        prev = root->val;
        
        return inorder(root->right);
    }

    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
};