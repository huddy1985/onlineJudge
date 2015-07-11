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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(NULL == l1) return l2;
        if(NULL == l2) return l1;
        ListNode *pFirst = new ListNode(l1->val+l2->val);
        ListNode *pNode = pFirst;
        while(l1->next && l2->next){
            l1 = l1->next;
            l2 = l2->next;
            pNode->next = new ListNode(l1->val+l2->val);
            pNode = pNode->next;
        }
        if(NULL == l1->next){
            pNode->next = l2->next;
        }
        else{
            pNode->next = l1->next;
        }
        pNode = pFirst;
        int carry = pNode->val/10;
        pNode->val = pNode->val%10;
        while(pNode->next){
            pNode = pNode->next;
            int temp = pNode->val + carry;
            pNode->val = temp%10;
            carry = temp/10;
        }
        if(carry > 0)
            pNode->next = new ListNode(carry);
        return pFirst;
    }
};