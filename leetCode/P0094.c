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
public:
    void _inorderTraversal(TreeNode* root){
        if(NULL == root)
            return ;
        _inorderTraversal(root->left);
        vec.push_back(root->val);
        _inorderTraversal(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        _inorderTraversal(root);
        return vec;
    }
};