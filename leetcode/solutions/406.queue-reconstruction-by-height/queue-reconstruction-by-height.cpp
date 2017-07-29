typedef pair<int,int> PII;
class Solution {
    struct Node;
    static int getSz(Node *t){return t==NULL?0:t->sz;}
    struct Node{
        int val;
        int sz;
        Node *left,*right;
        Node(int v, Node* l=0,Node* r = 0):val(v),left(l),right(r){
            sz = getSz(left)+getSz(right)+1;
        }
    };

    Node *build(int beg, int endd) {
        if (beg > endd) {
		    return NULL;
    	}
    	if (beg == endd) {
    		return new Node(beg,0,0);
    	}
    	int mid = (beg+endd)/2;
    	Node *l = build(beg,mid-1);
    	Node *r = build(mid+1,endd);
    	return new Node(mid,l,r);
    }

    
    int getKth(Node* rt,int k){
    	if (rt->val && k == getSz(rt)-getSz(rt->right)) {
    	    rt->sz--;
    	    int ret = rt->val;
    	    rt->val = 0;
    	    return ret;
    	}
    	else if (k<=getSz(rt)-getSz(rt->right)){
    		rt->sz--;
    		return getKth(rt->left,k);
    	}else{
    	    int ret;
    	    ret = getKth(rt->right,k-(getSz(rt)-getSz(rt->right)));
    		rt->sz--;
    		return ret;
    	}
    }

    static bool cmp (const PII& a, const PII &b) {
        return a.first == b.first? a.second > b.second : a.first<b.first;
    }

public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<PII> ret;
        int len = people.size();
        if (len == 0) return ret;
        sort(people.begin(), people.end(),cmp);
        Node *root = build(1,len);
        ret.resize(len);
        for (int i=0; i<len; ++i) {
            int pos = getKth(root, people[i].second+1);
            ret[pos-1] = people[i];
        }
        return ret;
    }
};