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
public:
    bool _isBalanced(TreeNode* root,int *h){
        if(NULL == root){
            *h = 0;
            return true;
        }
        int h_left,h_right;
        if(!_isBalanced(root->left,&h_left)){
            return false;
        }
        if(!_isBalanced(root->right,&h_right)){
            return false;
        }
        if((h_left-h_right)>=-1 && (h_left-h_right)<=1){
            *h = h_left>h_right?h_left+1:h_right+1;
            return true;
        }else
            return false;
    }
    bool isBalanced(TreeNode* root) {
        if(NULL == root)
            return true;
        int h;
        return _isBalanced(root,&h);
    }
};