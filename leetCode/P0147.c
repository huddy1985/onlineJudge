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
    ListNode* insertionSortList(ListNode* head) {
        if(NULL == head)
            return NULL;
        ListNode *pNode = head->next;
        ListNode *pHead = head;
        while(pNode){
            pHead = head;
            if(pNode->val < pHead->val){
                int temp1 = pNode->val;
                int temp2 = pHead->val;
                pHead->val = temp1;
                pHead = pHead->next;
                while(pHead != pNode){
                    temp1 = pHead->val;
                    pHead->val = temp2;
                    pHead = pHead->next;
                    temp2 = temp1;
                }
                pHead->val = temp2;
                pNode = pNode->next;
                continue;
            }
            while(pHead->next != pNode){
                if(pHead->next->val > pNode->val){
                    int temp1 = pNode->val;
                    int temp2 = pHead->next->val;
                    pHead->next->val = temp1;
                    pHead = pHead->next->next;
                    while(pHead != pNode){
                        temp1 = pHead->val;
                        pHead->val = temp2;
                        pHead = pHead->next;
                        temp2 = temp1;
                    }
                    pHead->val = temp2;
                    break;
                }
                pHead = pHead->next;
            }
            pNode = pNode->next;
        }
        return head;
    }
};