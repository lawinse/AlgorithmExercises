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
    TreeNode *prev = 0, *fir = 0, *sec = 0;
    void inorder(TreeNode *root){
        if (root->left)inorder(root->left);
        if (prev && root->val< prev->val){
            if (fir) sec = root;
            else {fir = prev, sec = root;}
        }
        prev  =root;
        if (root->right)inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        if (root)inorder(root);
        if (fir && sec){
            swap(fir->val,sec->val);
        }
    }
};