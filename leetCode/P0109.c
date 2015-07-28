/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* createBST(int s,int t){
        if(s==t){
            TreeNode* pNode = new TreeNode(vec[s]);
            return pNode;
        }else if(s > t)
            return NULL;
        int mid = (s+t)/2;
        TreeNode *pLeft = createBST(s,mid-1);
        TreeNode *pRight = createBST(mid+1,t);
        TreeNode* pRoot = new TreeNode(vec[mid]);
        pRoot->left = pLeft;
        pRoot->right = pRight;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(NULL == head)
            return NULL;
        while(head){
            vec.push_back(head->val);
            head = head->next;
        }
        return createBST(0,vec.size()-1);
    }
};