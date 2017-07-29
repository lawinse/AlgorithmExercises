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
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode *q = root->right;
        root->right = root->left;
        root->left = NULL;
        TreeNode *tmp = root;
        while(tmp->right) tmp = tmp->right;
        tmp->right = q;
        tmp->left = NULL;
        
    }
};