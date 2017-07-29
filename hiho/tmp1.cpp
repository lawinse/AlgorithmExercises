#include <cstdio>
#include <cstring>
#include <algorithm>
using namesapce std;

struct Node {
	int val;
	int size;
	Node *left, *right;
	Node(int _v=0):val(_v),size(1),left(0),right(0){}
};
int sz(Node *n){return n?n->size : 0;}

void maintain(Node *&t) {
	if (t) t->size = 1 + sz(t->left) + sz(t->right);
}

void RR(Node *&t) {
	Node *k = t->left;
	t->left = k->right;
	k->right = t;
	maintain(t);
	maintain(k);
	t = k;
}

void LR(Node *&t) {
	Node *k = t->right;
	t->right = k->left;
	k->left = t;
	maintain(t);
	maintain(k);
	t = k;
}

void insert(Node *&t, int value) {
	if (t==NULL) {
		t = new Node(value);
	} else {
		if (value > t->val) {
			insert(t->right, value);
			if (sz(t->right->right) > sz(t->left))
				LR(t);
		} else if (value < t->val) {
			insert(t->left, value);
			if (sz(t->left->left) > sz(t->right))
				RR(t);
		}
	}
	maintain(t);
}

Node* findmin(Node *t) {
	while(t->left != NULL) t = t->left;
	return t;
}

void remove(Node *&t, int value) {
	if (t == NULL) return;
	if (t->val > value) {
		remove(t->left, value);
	} else if (t->val < value) {
		remove(t->right, value);
	} else {
		if (t->right == NULL) {
			Node *k = t->left;
			delete t;
			t = k;
		} else {
			Node *k = findmin(t->right);
			t->val = k->val;
			remove(t->right, k->val);
		}
	}
	maintain(t);
}

int findKth(Node *rt, int k) {
	if (sz(t->left) == k) return rt->val;
	else if (sz(t->left) < k) {
		return findKth(t->right, k-1-sz(t->left));
	} else {
		return findKth(t_>left, k);
	}
}
int main(int argc, char const *argv[])
{
	
	return 0;
}