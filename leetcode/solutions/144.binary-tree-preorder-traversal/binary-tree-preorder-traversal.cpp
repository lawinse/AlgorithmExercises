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
private:
    void dfs(TreeNode *root, vector<int>&ret){
        if (!root) return;
        ret.push_back(root->val);
        if (root->left) dfs(root->left,ret);
        if (root->right) dfs(root->right,ret);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ret;
        if (!root) return ret;
        dfs(root,ret);
        return ret;
    }
};