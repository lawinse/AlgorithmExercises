/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode *head;
    int len;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        srand(time(0));
        this->head = head;
        len = 0;
        ListNode *p = head;
        while(p) {
            len++;
            p = p->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int ran = rand()%len;
        ListNode *p = head;
        while(ran--) {
            p = p->next;
        }
        return p->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */