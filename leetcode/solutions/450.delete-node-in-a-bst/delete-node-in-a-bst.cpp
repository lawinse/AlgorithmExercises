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
    TreeNode* findmin(TreeNode* t) {
        while(t->left) t = t->left;
        return t;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        if (root->val == key) {
            if (!root->left || !root->right) root = (root->left) ? root->left : root->right;
            else {
                auto tmp = findmin(root->right);
                root->val = tmp->val;
                root->right = deleteNode(root->right, tmp->val);
            }
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else root->right = deleteNode(root->right, key);
        return root;
    }
};