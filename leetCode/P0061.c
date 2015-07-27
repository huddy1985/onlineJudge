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
    ListNode* rotateRight(ListNode* head, int k) {
        if(NULL == head)
            return NULL;
        ListNode *pNode = head;  
        int len = 0;
        while(pNode){
            len ++;
            pNode = pNode->next;
        }
        k = k%len;
        ListNode *pFirst = head;
        ListNode *pLast = head;
        int i = k;
        while(i--){
            pFirst = pFirst->next;
            if(NULL == pFirst)
                pFirst = head;
        }
        while(pFirst->next){
            pFirst = pFirst->next;
            pLast = pLast->next;
        }
        pFirst->next = head;
        head = pLast->next;
        pLast->next = NULL;
        return head;
        
    }
};