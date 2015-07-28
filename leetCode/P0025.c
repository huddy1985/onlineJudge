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
    ListNode* reverse(ListNode* pStart,ListNode* pEnd){
        ListNode *pNode = pStart,*pTemp = NULL;
        pStart = pStart->next;
        pNode->next = NULL;
        while(pStart != pEnd){
            pTemp = pStart;
            pStart = pStart->next;
            pTemp->next = pNode;
            pNode = pTemp;
        }
        return pNode;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(NULL == head || k == 0 || k == 1)
            return head;
        ListNode *pStart = head,*pEnd = head;
        ListNode *pHead = NULL,*pNode=NULL;
        int cnt = 0;
        while(pEnd){
            cnt ++;
            pEnd = pEnd->next;
            if(cnt == k){
                pNode = reverse(pStart,pEnd);
                if(NULL == pHead){
                    head = pNode;
                    pHead = pStart;
                }else{
                    pHead->next = pNode;
                    pHead = pStart;
                }
                pStart = pEnd;
                cnt = 0;
            }
        }
        if(NULL == pHead){
            head = pStart;
        }else{
            pHead->next = pStart;
        }
        return head;
    }
};