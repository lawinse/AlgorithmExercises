/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode *cur = root;
        TreeLinkNode *head = NULL, *prev = NULL;
        while(cur) {
            while(cur) {
                if (cur->left) {
                    if (prev) {
                        prev->next = cur->left;
                    } else head = cur->left;
                    prev = cur->left;
                }
                if (cur->right) {
                    if (prev) prev->next = cur->right;
                    else head = cur->right;
                    prev = cur->right;
                }
                cur = cur->next;
            }
            cur = head;
            head = NULL;
            prev = NULL;
        }
 
    }
};