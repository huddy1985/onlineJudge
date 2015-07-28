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
        int flag = head->val;
        ListNode *pNode = head->next;
        ListNode *pHead = head;
        while(pNode){
            if(flag == pNode->val){
                pHead->next = pNode->next;
                delete pNode;
                pNode = pHead->next;
            }else{
                flag = pNode->val;
                pNode = pNode->next;
                pHead = pHead->next;
            }
        }
        return head;
    }
};