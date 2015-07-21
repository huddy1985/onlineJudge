/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<int> vec;
    void pre(TreeNode* root){
        if(NULL == root)
            return;
        vec.push_back(root->val);
        pre(root->left);
        pre(root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        pre(root);
        return vec;
    }
};