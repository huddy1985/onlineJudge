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
    vector<vector<int>> res;
    vector<int> vec;
    void _pathSum(TreeNode* root, int sum){
        if(root == NULL)
            return ;
        vec.push_back(root->val);
        if(root->left == NULL && root->right == NULL && sum == root->val){
            res.push_back(vec);
            return ;
        }
        _pathSum(root->left, sum-root->val);
        if(root->left)
            vec.pop_back();
        _pathSum(root->right, sum-root->val);
        if(root->right)
            vec.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(NULL == root)
            return res;
        _pathSum(root, sum);
        return res;
    }
};