/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(NULL == node || NULL == node->next)
            return ;
        node->val = node->next->val;
        ListNode *pNode = node->next;
        node->next = pNode->next;
        delete pNode;
    }
};