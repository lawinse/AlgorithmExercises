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
    void dfs(TreeNode *cur, int rest, vector<int> & path, vector< vector<int> > & ret){
        if (cur->left == NULL && cur->right == NULL && rest == cur->val){
            path.push_back(cur->val);
            ret.push_back(path);
            path.pop_back();
            return;
        }
        if (cur->left){
            path.push_back(cur->val);
            dfs(cur->left,rest-cur->val,path,ret);
            path.pop_back();
        }
        if (cur->right){
            path.push_back(cur->val);
            dfs(cur->right,rest-cur->val,path,ret);
            path.pop_back();
        }
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector< vector<int>> ret;
        vector<int> path;
        if (root == NULL) return ret;
        dfs(root,sum,path,ret);
        return ret;
    }
};