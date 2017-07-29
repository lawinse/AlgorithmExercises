
        /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 ListNode * rev(ListNode *srt, ListNode *endd)
 {
     if (srt == endd || srt->next == endd) return srt;
     ListNode *p1 = srt;
     ListNode *p2 = p1->next;
     ListNode *p3 = p2->next;
     p1->next = endd;
     while(p3!=endd)
     {
         p2->next = p1;
         p1 = p2;
         p2 = p3;
         p3 = p3->next;
     }
     p2->next = p1;
     srt = p2;
     return srt;
 }

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *hair = new ListNode(0);
        hair->next = head;
        ListNode *p = hair,*q = NULL,*beg = NULL;
        while(true)
        {
            bool f = 1;
            beg = p->next;
            q = p;
            for (int i = 0 ;i < k ;++i){
                if (p && p->next) p = p->next;
                else {f = 0;break;}
            }
            if (!f) break;
            //cout << beg->val <<" "<<p->next->val<<endl;

            q->next = rev(beg,p->next);
            p = beg;
           // cout << beg->val<<endl;




        }
        return hair->next;
    }
};
        