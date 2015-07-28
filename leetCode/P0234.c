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
    bool isPalindrome(ListNode* head) {
        if(NULL == head)
            return true;
        if(NULL == head->next)
            return true;
        ListNode *pFirst = head->next,*pLast = head;
        ListNode *pNode = NULL,*pMid = NULL;
        while(pFirst){
            pFirst = pFirst->next;
            if(NULL == pFirst)
                break;
            pFirst = pFirst->next;
            pLast = pLast->next;
        }
        bool res = true;
        pMid = pLast;
        pFirst = pLast->next;
        while(pFirst){
            pNode = pFirst;
            pFirst = pFirst->next;
            pNode->next = pLast;
            pLast = pNode;
        }
        pFirst = head;
        pNode = pLast;
        while(pFirst != pMid && pLast != pMid){
            if(pFirst->val != pLast->val)
                res = false;
            pFirst = pFirst->next;
            pLast = pLast->next;
        }
        if(pFirst->val != pLast->val)
            res = false;
        pFirst = pNode->next;
        pNode->next = NULL;
        while(pFirst != pMid){
            pLast = pNode;
            pNode = pFirst;
            pFirst = pFirst->next;
            pNode->next = pLast;
        }
        return res;
    }
};