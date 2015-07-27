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
    void reorderList(ListNode* head) {
        if(NULL == head || NULL == head->next)
            return ;
        vector<int> vec;
        ListNode *pNode = head;
        while(pNode){
            vec.push_back(pNode->val);
            pNode = pNode->next;
        }
        pNode = head;
        int len = vec.size();
        int start = 0,end = len-1;
        while(pNode && pNode->next){
            pNode->val = vec[start];
            pNode->next->val = vec[end];
            pNode = pNode->next->next;
            start ++;
            end --;
        }
        if(pNode)
            pNode->val = vec[start];
    }
};



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
    void reorderList(ListNode* head) {
        if(NULL == head || NULL == head->next)
			return ;
        vector<ListNode*> vec;
        ListNode *pNode = head;
        while(pNode){
            vec.push_back(pNode);
            pNode = pNode->next;
        }
        pNode = head;
        ListNode *pHead = pNode->next;
        int len = vec.size();
        int start = 0,end = len-1;
        while(start < end-1){
            pNode->next = vec[end];
            pNode = pNode->next;
            pNode->next = pHead;
            pNode = pNode->next;
            pHead = pHead->next;
            start ++;
            end --;
        }
        if(start == end)
            pNode->next = NULL;
        else{
            pHead->next = NULL;
        }
    }
};



