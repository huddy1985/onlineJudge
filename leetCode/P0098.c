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
    vector<int> nums;
public:
    void midOrder(TreeNode* root){
        if(NULL == root)
            return;
        midOrder(root->left);
        nums.push_back(root->val);
        midOrder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if(NULL == root)
            return true;
        midOrder(root);
        int i;
        for(i=1; i<nums.size(); i++)
            if(nums[i] <= nums[i-1])
                return false;
        return true;
    }
};