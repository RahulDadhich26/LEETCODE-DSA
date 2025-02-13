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
    void inorder(TreeNode* root , TreeNode* &first , TreeNode* &sec , TreeNode* &prev ) {
        if(root == NULL) return;
        inorder(root->left, first ,sec, prev);
        if(prev && root->val < prev->val){
            if(!first) first = prev;
            sec = root;
        }
        prev = root;
        inorder(root->right, first ,sec, prev);
    }
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr , *sec = nullptr, *prev = nullptr;
        inorder(root , first ,sec, prev);
        if(first && sec){
            int temp = first -> val;
            first->val = sec->val;
            sec->val = temp;
        }
    }
};