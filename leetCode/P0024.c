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
    ListNode* swapPairs(ListNode* head) {
        if(NULL == head)
            return NULL;
        ListNode *pPre = head;
        ListNode *pPost = head->next;
        while(pPost){
            int temp = pPost->val;
            pPost->val = pPre->val;
            pPre->val = temp;
            pPre = pPost->next;
            if(NULL == pPre)
                break;
            pPost = pPre->next;
        }
        return head;
    }
};