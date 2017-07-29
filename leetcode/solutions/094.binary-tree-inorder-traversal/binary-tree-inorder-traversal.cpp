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
    void ind(TreeNode *root, vector<int>&ret) {
        if (!root) return;
        if (root->left) ind(root->left,ret);
        ret.push_back(root->val);
        if (root->right) ind(root->right, ret);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ret;
        if (!root) return ret;
        ind(root, ret);
        return ret;
    }
};