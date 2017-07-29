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
    void post (TreeNode* root, vector<int> &ret) {
        if (!root) return;
        if (root->left) post(root->left, ret);
        if (root->right) post(root->right, ret);
        ret.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root) return ret;
        post(root, ret);
        return ret;
        
    }
};