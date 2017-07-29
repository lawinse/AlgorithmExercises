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
        ListNode *head = new ListNode(0),*p  = head;
         int n1,n2;
        
        while(l1 != NULL && l2 != NULL)
        {
           
            n1 = l1->val;
            n2 = l2->val;
            if (n1 < n2){
                p ->next = new ListNode(n1);
                p = p->next;
                l1 = l1->next;
            }
            else {
                p ->next = new ListNode(n2);
                p = p->next;
                l2 =l2->next;
            }
        }
        if (l1 != NULL){
            p -> next= l1;
        }
        else {
            p -> next= l2;
        }
        return head->next;
    }
};