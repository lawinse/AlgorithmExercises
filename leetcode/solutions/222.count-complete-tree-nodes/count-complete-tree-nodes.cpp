/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
typedef TreeNode Node;
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        Node* l = root->left;
        Node *r = root->right;
        int l1 = 0, l2 = 0;
        while(l) l= l->left, ++l1;
        while(r) r = r->right, ++l2;
        return l1 == l2 ? (2<<l1) - 1 : 1 + countNodes(root->left) + countNodes(root->right);
    }
};