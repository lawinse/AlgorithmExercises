/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
typedef RandomListNode RLN;
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RLN *newHead, *l1, *l2;
        if (!head) return NULL;
        for (l1=head; l1; l1=l1->next->next) {
            l2 = new RLN(l1->label);
            l2->next = l1->next;
            l1->next = l2;
        }
        
        newHead = head->next;
        for (l1=head;l1;l1=l1->next->next){
            if (l1->random!=NULL) l1->next->random = l1->random->next;
        }
        for (l1=head;l1;l1=l1->next){
            l2 = l1->next;
            l1->next = l2->next;
            if (l2->next!=NULL) l2->next = l2->next->next;
        }
        return newHead;
    }
};