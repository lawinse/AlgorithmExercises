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
    unordered_map<int,int>mp;
    int ttl;
    TreeNode *Build(vector<int> &preO, int preL, int preR, vector<int> &inO, int inL, int inR){
        //if (preL>preR) return NULL;
        int rootVal = preO[preL];
        int rootPosinInOrder = mp[rootVal];

        // int tmp = inO[rootPosinInOrder-1];
        int rightEndinPre = preL+(rootPosinInOrder-inL);
        TreeNode *root = new TreeNode(rootVal);
        root->left = (preL+1<=rightEndinPre)?Build(preO,preL+1,rightEndinPre,inO,inL,rootPosinInOrder-1):NULL;
        root->right = (rightEndinPre+1<=preR)?Build(preO,rightEndinPre+1,preR,inO,rootPosinInOrder+1,inR):NULL;
        return root;
        
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        int n = preorder.size();
        for (int i=0; i<n; ++i) mp[inorder[i]] = i;
        return Build(preorder,0,n-1,inorder,0,n-1);
    }
};