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
    ListNode* reverseList(ListNode* head) {
        if(NULL == head)
            return NULL;
        ListNode *pHead = head;
        ListNode *pNode = head->next;
        head->next = NULL;
        while(pNode){
            head = pNode->next;
            pNode->next = pHead;
            pHead = pNode;
            pNode = head;
        }
        return pHead;
    }
};