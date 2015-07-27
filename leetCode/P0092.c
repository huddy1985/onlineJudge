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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(NULL == head || m==n)
            return head;
        ListNode *pA=NULL,*pB=NULL,*pHead = head;
        int a = m<n?m:n;
        int b = m<n?n:m;
        int cnt = 0;
        vector<int> vec;
        while(pHead){
            cnt ++;
            if(cnt == a && NULL == pA){
                pA = pHead;
                vec.push_back(pHead->val);
            }
            else if(cnt == b && NULL == pB){
                pB = pHead;
                vec.push_back(pHead->val);
                break;
            }
            if(pA)
                vec.push_back(pHead->val);
            pHead = pHead->next;
        }
        int temp = pA->val;
        int len = vec.size();
        cnt = 0;
        while(pA != pB){    
            pA->val = vec[len-1-cnt];
            cnt ++;
            pA = pA->next;
        }
        pB->val = vec[0];
        return head;
    }
};