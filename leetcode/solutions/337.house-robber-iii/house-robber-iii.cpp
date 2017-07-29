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
    void dfs(TreeNode *rt, int &rob, int &nrob){
        if (!rt) return;
        rob = rt->val;
        nrob = 0;
        int tmpRob, tmpNRob;
        if (rt->left){
            dfs(rt->left,tmpRob,tmpNRob);
            rob += tmpNRob;
            nrob += max(tmpRob,tmpNRob);
        }
        if (rt->right){
            dfs(rt->right,tmpRob,tmpNRob);
            rob += tmpNRob;
            nrob += max(tmpRob,tmpNRob);
        }
    }
    
    
    
public:
    int rob(TreeNode* root) {
        int ret = 0;
        int r = 0,nr = 0;
        dfs(root,r,nr);
        ret = max(r,nr);
        return ret;
        
    }
};