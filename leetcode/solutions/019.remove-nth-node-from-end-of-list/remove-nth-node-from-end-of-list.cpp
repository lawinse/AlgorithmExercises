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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *q = head,*tmp = NULL;
        while(n--) p = p->next;
        if (!p) {tmp =  head->next; delete head; return tmp;}
        while(p->next){
            p = p->next;
            q = q->next;
        }
        tmp = q->next;
        q->next = tmp->next;
        delete tmp;
        return head;
        
        
    }
};