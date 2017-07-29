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
    int dfs(TreeNode *cur, int &curMax) {
        if (!cur) return 0;
        int lm = dfs(cur->left, curMax);
        int rm = dfs(cur->right, curMax);
        curMax = max(cur->val + max(lm,0) + max(rm,0), curMax);
        return cur->val + max(max(lm,rm),0);
    }

    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int ret = INT_MIN;
        dfs(root, ret);
        return ret;
    }
};
