/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.

    string serialize(TreeNode* root) {
        if(!root)return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
     }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string>nodes;
        stringstream ss(data);
        string item;
        while(getline(ss, item , ',')){
           nodes.push(item);
        }
        return deserializeHelper(nodes);
    }
private:
   TreeNode* deserializeHelper(queue<string>&nodes){
        string val = nodes.front();
        nodes.pop();
        if(val == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserializeHelper(nodes);
        root->right = deserializeHelper(nodes);
        return root;
   }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));