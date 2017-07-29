// http://hihocoder.com/problemset/problem/1337
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

struct Node {
	int size;
	int key;
	Node *left,*right;
	Node(int _k = 0):size(1),left(NULL),right(NULL),key(_k){}
};

int sz(Node *t){return t==NULL? 0:t->size;}

void maintain(Node *t) {
	if (t) {
		t->size = 1 + sz(t->left) + sz(t->right);
	}
}

void RR(Node *&t){
	Node* k = t->left;
	t->left = k->right;
	k->right = t;
	maintain(t);
	maintain(k);
	t = k;
}

void LL(Node *&t) {
	Node* k = t->right;
	t->right = k->left;
	k->left = t;
	maintain(t);
	maintain(k);
	t = k;
}

void insert(Node *&t, int value) {
	if (t == NULL) {
		t = new Node(value);
	} else {
		if (value < t->key) {
			insert(t->left, value);
			if (sz(t->left->left) > sz(t->right))
				RR(t);
		} else if (value > t->key) {
			insert(t->right, value);
			if (sz(t->right->right) > sz(t->left))
				LL(t);
		}
	}
	maintain(t);
}

Node* findmin(Node *t) {
	while(t->left!=NULL) {
		t = t->left;
	}
	return t;
}

void remove(Node *&t, int value) {
	if (t == NULL) return;
	if (t->key == value) {
		if (t->right == NULL) {
			Node * tmp = t->left;
			delete t;
			t = tmp;
		} else {
			// Node* sel = findmin(t->right);
			// remove(t->right,sel->key);
			// sel->left = t->left;
			// sel->right = t->right;
			// t = sel;
			Node* sel = findmin(t->right);
			t->key = sel->key;
			remove(t->right,sel->key)
		}
	} else if(value < t->key) {
		remove(t->left,value);
	} else remove(t->right, value);
	maintain(t);
}

int findKth(Node* t, int k) {
	if (sz(t->left) == k) {
		return t->key;
	} else if (sz(t->left) > k) {
		return findKth(t->left,k);
	} else return findKth(t->right, k-1-sz(t->left));
}

int main(int argc, char const *argv[])
{
	Node *root = NULL;
	int N;
	cin >> N;
	while(N--) {
		string op;
		int operand;
		cin >> op >> operand;
		if(op == "I") {
			insert(root,operand);
		} else {
			cout << findKth(root, operand-1) << endl;
		}
	}
 	return 0;
}