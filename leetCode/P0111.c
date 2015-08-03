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
    int min(int a,int b){
        return a<b?a:b;
    }
    int _minDepth(TreeNode* root){
        if(NULL == root)
            return 0;
        if(root->left && root->right){
            int left = _minDepth(root->left);
            int right = _minDepth(root->right);
            return min(left,right)+1;
        }
        else if(NULL == root->left)
            return _minDepth(root->right)+1;
        else
            return _minDepth(root->left)+1;
    }
public:
    int minDepth(TreeNode* root) {
        return _minDepth(root);
    }
};