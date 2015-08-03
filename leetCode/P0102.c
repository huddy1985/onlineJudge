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
    vector<vector<int>> vvec;
    vector<int> vec;
    list<TreeNode*> lst1;
    list<TreeNode*> lst2;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(NULL == root)
            return vvec;
        vec.push_back(root->val);
        vvec.push_back(vec);
        vec.clear();
        if(root->left)
            lst1.push_back(root->left);
        if(root->right)
            lst1.push_back(root->right);
        while(!lst1.empty() || !lst2.empty()){
            while(!lst1.empty()){
                root = lst1.front();
                lst1.pop_front();
                vec.push_back(root->val);
                if(root->left)
                    lst2.push_back(root->left);
                if(root->right)
                    lst2.push_back(root->right);
            }
            if(!vec.empty()){
                vvec.push_back(vec);
                vec.clear();
            }
            while(!lst2.empty()){
                root = lst2.front();
                lst2.pop_front();
                vec.push_back(root->val);
                if(root->left)
                    lst1.push_back(root->left);
                if(root->right)
                    lst1.push_back(root->right);
            }
            if(!vec.empty()){
                vvec.push_back(vec);
                vec.clear();
            }
        }
        return vvec;
    }
};