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
    ListNode* partition(ListNode* head, int x) {
        if(NULL == head)
            return NULL;
        ListNode *pMin = NULL,*pMax = NULL,*pNode = head;
        ListNode *pMinHead = NULL,*pMaxHead = NULL;
        while(pNode){
            if(pNode->val < x){
                if(NULL == pMin)
                    pMinHead = pMin = pNode;
                else{
                    pMin->next = pNode;
                    pMin = pMin->next;
                }
            }else{
                if(NULL == pMax)
                    pMaxHead = pMax = pNode;
                else{
                    pMax->next = pNode;
                    pMax = pMax->next;
                }
            }
            pNode = pNode->next;
        }
        if(NULL == pMinHead)
            return pMaxHead;
        else{
            pMin->next = pMaxHead;
            if(pMax)
                pMax->next = NULL;
        }
        return pMinHead;
    }
};