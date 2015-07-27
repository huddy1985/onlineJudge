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
    ListNode* sortList(ListNode* head) {
        if(NULL == head)
            return NULL;
        vector<int> vec;
        ListNode *pNode = head;
        while(pNode){
            vec.push_back(pNode->val);
            pNode = pNode->next;
        }
        sort(vec.begin(),vec.end());
        pNode = head;
        vector<int>::iterator it;
        for(it=vec.begin();it!=vec.end();it++){
            pNode->val = *it;
            pNode = pNode->next;
        }
        return head;
    }
};