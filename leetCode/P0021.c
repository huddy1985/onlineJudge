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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(NULL == l1 && NULL == l2)
            return NULL;
        if(NULL == l1)
            return l2;
        if(NULL == l2)
            return l1;
        ListNode *head = NULL;
        if(l1->val < l2->val){
            head = l1;
            l1 = l1->next;
        }else{
            head = l2;
            l2 = l2->next;
        }
        ListNode *pHead = head;
        while(l1 && l2){
            if(l1->val < l2->val){
                pHead->next = l1;
                l1 = l1->next;
            }else{
                pHead->next = l2;
                l2 = l2->next;
            }
            pHead = pHead->next;
        }
        if(l1)
            pHead->next = l1;
        else
            pHead->next = l2;
        return head;
    }
};