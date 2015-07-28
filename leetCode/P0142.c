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
    ListNode *detectCycle(ListNode *head) {
        if(NULL == head)
            return NULL;
        ListNode *pFirst = head->next,*pLast = head;
        if(NULL == pFirst)
            return NULL;
        while(pFirst){
            if(pFirst == pLast)
                break;
            pFirst = pFirst->next;
            if(pFirst == NULL)
                return NULL;
            pFirst = pFirst->next;
            pLast = pLast->next;
        }
        if(NULL == pFirst)
            return NULL;
        pLast = head;
        pFirst = pFirst->next;
        while(pLast != pFirst){
            pLast = pLast->next;
            pFirst = pFirst->next;
        }
        return pFirst;
    }
};