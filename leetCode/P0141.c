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
    bool hasCycle(ListNode *head) {
        if(NULL == head)
            return false;
        ListNode *pFirst = head->next,*pLast = head;
        while(pFirst){
            if(pFirst == pLast)
                return true;
            pFirst = pFirst->next;
            if(NULL == pFirst)
                return false;
            pFirst = pFirst->next;
            pLast = pLast->next;
        }
        return false;
    }
};