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
    ListNode* removeElements(ListNode* head, int val) {
        if(NULL == head)
            return NULL;
        ListNode* pNode = NULL;
        while(head && val == head->val){
            pNode = head;
            head = head->next;
            delete pNode;
        }
        if(NULL == head)
            return NULL;
        ListNode *pHead = head;
        pNode = head->next;
        while(pNode){
            if(val == pNode->val){
                pHead->next = pNode->next;
                delete pNode;
                pNode = pHead->next;
            }
            else{
                pNode = pNode->next;
                pHead = pHead->next;
            }
        }
        return head;
    }
};