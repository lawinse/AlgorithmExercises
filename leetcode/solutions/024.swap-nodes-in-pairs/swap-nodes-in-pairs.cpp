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
        ListNode *hair = new ListNode(0);
        hair->next = head;
        ListNode *p = hair;
        ListNode *fir = NULL, *sec = NULL;
        while(p->next && p->next->next){
            fir = p->next;
            sec = fir->next;
            p->next = sec;
            fir->next = sec->next;
            sec->next = fir;
            p = p->next->next;
        }
        return hair->next;
    }
};