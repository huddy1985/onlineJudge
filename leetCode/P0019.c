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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(NULL == head)
            return head;
        ListNode *pFirst = head,*pLast = NULL;
        while(--n){
            pFirst = pFirst->next;
            if(NULL == pFirst)
                return head;
        }
        while(pFirst->next){
            if(NULL == pLast)
                pLast = head;
            else{
                pLast = pLast->next;
            }
            pFirst = pFirst->next;
        }
        if(NULL == pLast){
            pFirst = head;
            head = head->next;
        }else{
            pFirst = pLast->next;
            pLast->next = pFirst->next;
        }
        delete pFirst;
        return head;
    }
};