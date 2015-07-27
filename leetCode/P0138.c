/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(NULL == head)
            return NULL;
        RandomListNode *pCopy,*pNode;
        pNode = head;
        while(pNode){
            pCopy = new RandomListNode(pNode->label);
            pCopy->random = pNode->random;
            pCopy->next = pNode->next;
            pNode->next = pCopy;
            pNode = pCopy->next;
        }
        pNode = head;
        while(pNode){
            pCopy = pNode->next;
            if(NULL != pCopy->random)
                pCopy->random = pCopy->random->next;
            pNode = pCopy->next;
        }
        RandomListNode *pCopyHead = head->next;
        pNode = head->next->next;
        head->next = pNode;
        head = pNode;
        pCopy = pCopyHead;
        while(pNode){
            pCopy->next = pNode->next;
            pCopy = pCopy->next;
            pNode = pCopy->next;
            head->next = pNode;
            head = pNode;
        }
        return pCopyHead;
    }
};