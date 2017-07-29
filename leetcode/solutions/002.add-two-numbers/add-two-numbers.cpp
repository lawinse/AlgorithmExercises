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
        int carry = 0;
        ListNode *Head = new ListNode(0);
        ListNode *p = Head;
        while(l1 || l2)
        {
            int v1 = 0;
            int v2 = 0;
            if (l1)
            {
                v1 = l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                v2 = l2->val;
                l2 = l2->next;
            }
            
            int tmp = v1 + v2 + carry;
            p->next = new ListNode(tmp%10);
            p = p->next;
            carry = tmp/10;
            
        }
        if (carry == 1)
        {
            p->next = new ListNode(1);
        }
        return Head->next;
        
    }
};