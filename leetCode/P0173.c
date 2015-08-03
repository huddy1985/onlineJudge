/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> stk;
public:
    BSTIterator(TreeNode *root) {
        while(root){
            stk.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *pNode = stk.top();
        int res = pNode->val;
        stk.pop();
        if(pNode->right){
            stk.push(pNode->right);
            pNode = pNode->right;
            while(pNode->left){
                stk.push(pNode->left);
                pNode = pNode->left;
            }
        }
        return res;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */