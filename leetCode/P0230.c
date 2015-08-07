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
    int res;
public:
    bool getkthSmallest(TreeNode* root, int *k){
        if(NULL == root)
            return false;
        
        if(getkthSmallest(root->left,k))
            return true;
        
        if(1 == *k){
            res = root->val;
            return true;
        }
        (*k) = (*k) - 1;
        if(getkthSmallest(root->right,k))
            return true;

        return false;
    }
    int kthSmallest(TreeNode* root, int k) {
        getkthSmallest(root, &k);
        return res;
    }
};