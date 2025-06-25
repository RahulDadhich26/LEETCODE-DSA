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
    void traverse(TreeNode *root,vector<int> &a)
    {
        if(root != NULL)
        {
            traverse(root->left,a);
            a.push_back(root->val);
            traverse(root->right,a);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> n,m,res;
        traverse(root1,n);
        traverse(root2,m);
        int l=0,r=0;
        while(l<n.size() && r<m.size())
        {
            if(n[l]<m[r])
            {
                res.push_back(n[l]);
                l++;
            }
            else
            {
                res.push_back(m[r]);
                r++;
            }
        }
        while(l<n.size())
        {
            res.push_back(n[l]);
            l++;
        }
        while(r<m.size())
        {
            res.push_back(m[r]);
            r++;
        }
        return res;
    }
};