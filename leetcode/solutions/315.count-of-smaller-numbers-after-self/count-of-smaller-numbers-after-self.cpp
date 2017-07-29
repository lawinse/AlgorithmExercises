class Solution {
private:
    struct Node{
        int val;
        int cnt;
        int smallcnt;
        int size;
        Node *left, *right;
        Node(int _val):val(_val),cnt(1),smallcnt(0),left(0),right(0),size(1){};
    };
    
    int sz(Node *t){
        return (t==NULL)?0:t->size;
    }
    void maintain(Node *t){
        if (t) {
            t->size = 1+sz(t->left)+sz(t->right);
        }
    }
    
    void LL(Node *&t){
       Node *k = t->left;
       t->left = k->right;
       k->right = t;
       t->smallcnt -= (k->smallcnt + k->cnt);
       maintain(t);
       maintain(k);
       t = k;
    }
    
    void RR(Node *&t){
        Node *k = t->right;
        t->right = k->left;
        k->left = t;
        k->smallcnt += (t->smallcnt + t->cnt);
        maintain(t);
        maintain(k);
        t = k;
    }
    
    int BST(Node*& t, int v) {
        int ret;
        if (t->val == v){
            t->cnt++;
            return t->smallcnt;
        } else if (t->val > v) {
            t->smallcnt++;
            if (!t->left){
                t->left = new Node(v);
                ret = 0;
            } else {
                ret = BST(t->left,v);
            }
            if (sz(t->left->left) > sz(t->right)) LL(t);
        } else {
            if (!t->right) {
                t->right = new Node(v);
                ret =  t->smallcnt + t->cnt;
            } else {
                ret =  t->smallcnt + t->cnt + BST(t->right,v);
            }
            if (sz(t->right->right) > sz(t->left)) RR(t);
        }
        maintain(t);
        
        return ret;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ret;
        if (nums.size() == 0) return ret;
        ret = vector<int>(nums.size(),0);
        Node *root = new Node(nums.back());
        for (int i=nums.size()-2; i>=0; --i) {
            ret[i] = BST(root,nums[i]);
        }
        return ret;
    }
};