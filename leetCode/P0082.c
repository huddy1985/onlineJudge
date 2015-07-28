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
    ListNode* deleteDuplicates(ListNode* head) {
        if(NULL == head)
            return NULL;
        if(head->next == NULL)
            return head;
        ListNode *pFirst = head->next,*pLast = head,*pNode=NULL;
        ListNode *pHead = NULL;
        head = NULL;
        while(pFirst){
            if(pFirst->val == pLast->val){
                pFirst = pFirst->next;
            }else{
                if(pFirst == pLast->next){
                    if(pHead == NULL){
                        pHead = pLast;
                        head = pLast;
                    }else{
                        pHead->next = pLast;
                        pHead = pHead->next;
                    }
                }else{
                    while(pFirst != pLast){
                        pNode = pLast;
                        pLast = pLast->next;
                        delete pNode;
                    }
                }
                pLast = pFirst;
                pFirst = pFirst->next;
            }
        }
        if(pFirst == pLast->next){
            if(NULL == pHead){
                head = pLast;
                head->next = NULL;
            }else{
                pHead->next = pLast;
                pHead = pHead->next;
            }
        }
            
        if(pHead)
            pHead->next = NULL;
        return head;
    }
};