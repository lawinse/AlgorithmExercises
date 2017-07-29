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
    bool dfs(TreeNode *cur, int rest){
        if (cur->left == NULL && cur->right == NULL && rest == 0) return true;
        bool ret = false;
        if (cur->left){
            ret = dfs(cur->left,rest-cur->left->val);
        }
        if (cur->right && !ret){
            ret = dfs(cur->right,rest-cur->right->val);
        }
        return ret;
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
       // int rest = sum;
       if (root == NULL) return false;
        return dfs(root,sum-root->val);
    }
};