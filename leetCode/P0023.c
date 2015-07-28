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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(NULL == l1 && NULL == l2)
            return NULL;
        if(NULL == l1)
            return l2;
        if(NULL == l2)
            return l1;
        ListNode *head = NULL;
        if(l1->val < l2->val){
            head = l1;
            l1 = l1->next;
        }else{
            head = l2;
            l2 = l2->next;
        }
        ListNode *pHead = head;
        while(l1 && l2){
            if(l1->val < l2->val){
                pHead->next = l1;
                l1 = l1->next;
            }else{
                pHead->next = l2;
                l2 = l2->next;
            }
            pHead = pHead->next;
        }
        if(l1)
            pHead->next = l1;
        else
            pHead->next = l2;
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int i,len = lists.size();
        if(0 == len)
            return NULL;
        if(1 == len)
            return lists[0];
        vector<ListNode*> vec;
        ListNode *pList = NULL;
        for(i=0; i<len-1; i=i+2){
            pList =  mergeTwoLists(lists[i],lists[i+1]);
            vec.push_back(pList);
        }
        if(i == len-1)
            vec.push_back(lists[len-1]);
        while(true){
            vector<ListNode*> vec0;
            len = vec.size();
            if(len == 1)
                return vec[0];
            for(i=0; i<len-1; i=i+2){
                pList =  mergeTwoLists(vec[i],vec[i+1]);
                vec0.push_back(pList);
            }
            if(i == len-1)
                vec0.push_back(vec[len-1]);
            vec.clear();
            vec.resize(vec0.size());
            copy(vec0.begin(),vec0.end(),vec.begin());
        }
    }
};