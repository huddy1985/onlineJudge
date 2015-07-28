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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        ListNode *pHeadA = headA,*pHeadB = headB;
        while(pHeadA){
            lenA ++;
            pHeadA = pHeadA->next;
        }
        int lenB = 0;
        while(pHeadB){
            lenB ++;
            pHeadB = pHeadB->next;
        }
        pHeadA = headA;pHeadB = headB;
        if(lenA > lenB){
            int cnt = lenA - lenB;
            while(cnt--){
                pHeadA = pHeadA->next;
            }
        }else if(lenA < lenB){
            int cnt = lenB - lenA;
            while(cnt--){
                pHeadB = pHeadB->next;
            }
        }
        while(pHeadA && pHeadB){
            if(pHeadA == pHeadB){
                return pHeadA;
            }
            pHeadA = pHeadA->next;
            pHeadB = pHeadB->next;
        }
        return NULL;
    }
};