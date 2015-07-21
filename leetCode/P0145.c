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
    void post(TreeNode *root){
        if(NULL == root)
            return;
        post(root->left);
        post(root->right);
        vec.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        post(root);
        return vec;
    }
};