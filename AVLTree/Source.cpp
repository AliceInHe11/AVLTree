#include"Header.h"

void initTree (AVLTree& r) {
	r = NULL;
}

Nodeptr makeNode (int x) {
	Nodeptr p = new Node;
	if (p == NULL) return NULL;
	p->left = NULL;
	p->right = NULL;
	p->data = x;
	p->height = 1;

	return p;
}

int height (Nodeptr r) {
	if (r == NULL)
		return -1;
	else 
		return r->height;
}

void rotateRight (AVLTree& r) {
	if (r == NULL || r->left == NULL) return;

	Nodeptr p = r->left; // left subtree
	r->left = p->right;
	p->right = r;

	// update root node height
	int lr = height(r->left);
	int rr = height(r->right);
	r->height = 1 + (lr > rr ? lr : rr);
	// update subtree node height
	int lp = height(p->left);
	int rp = height(p->right);
	p->height = 1 + (lp > rp ? lp : rp);

	r = p; // reassign the root note
}

void rotateLeft (AVLTree& r) {
	if (r == NULL || r->right == NULL) return;

	Nodeptr p = r->right; // right subtree
	r->right = p->left;
	p->left = r;

	// update root node height
	int lr = height(r->left);
	int rr = height(r->right);
	r->height = 1 + (lr > rr ? lr : rr);
	// update subtree node height
	int lp = height(p->left);
	int rp = height(p->right);
	p->height = 1 + (lp > rp ? lp : rp);

	r = p; // reassign the root note
}

void rotateRightLeft (AVLTree& r) {
	if (r == NULL || r->left == NULL) return;
	rotateLeft(r->left);
	rotateRight(r);
}

void rotateLeftRight (AVLTree& r) {
	if (r == NULL || r->right == NULL) return;
	rotateRight(r->right);
	rotateLeft(r);
}

void balanceLeft (AVLTree& r) {
	if (r == NULL) return;

	if (height(r->left) - height(r->right) == 2) { //heights of left and right subtrees cannot be more than 1 for all nodes. 
		Nodeptr p = r->right;
		if (height(p->left) <= height(p->right))
			rotateLeft(r);
		else 
			rotateRightLeft(r);
	}
}

void balanceRight (AVLTree& r) {
	if (r == NULL) return;

	if (height(r->left) - height(r->right) == 2) { //heights of left and right subtrees cannot be more than 1 for all nodes.
		Nodeptr p = r->left;
		if (height(p->left) >= height(p->right)) 
			rotateRight(r);
		else 
			rotateLeftRight(r);
	}
}

void insertNode (AVLTree& r, int a) {
	if (r == NULL) 
		r = makeNode(a);
	else {
		if (a < r->data) { // insert left side, but better if(a<=r->data)
			insertNode(r->left, a);
			balanceRight(r);
		}
		if (a > r->data) { // insert right side
			insertNode(r->right, a);
			balanceLeft(r);
		}
		// update the height of new node
		int lr = height(r->left);
		int rr = height(r->right);
		r->height = 1 + (lr > rr ? lr : rr);
	}
}

void deleteNode(AVLTree& r, int x) {
	if (r == NULL) return;
	if (r->data > x)
		deleteNode(r->left, x); // leaf node
	else if (r->data < x)
		deleteNode(r->right, x); // leaf node

	else {// r->data==x
		if (r->left == NULL) { // if left sub tree is empty
			Nodeptr successorNode;
			successorNode = r;
			r = r->right;
			delete successorNode;
		}
		else if (r->right == NULL) { // if right sub tree is empty
			Nodeptr successorNode;
			successorNode = r;
			r = r->left;
			delete successorNode;
		}
		else { // if both sub tree exist => farthest node on the right side of left sub tree 
			Nodeptr farthestRightNode = r->left;
			while (farthestRightNode->right != NULL)
				farthestRightNode = farthestRightNode->right;
			r->data = farthestRightNode->data;
			deleteNode(r->left, farthestRightNode->data);
		}
	}
}

Nodeptr searchNode(AVLTree r, int x) {
	if (r == NULL || r->data == x) return r; // root is empty or key is present at root 
	if (r->data > x) return searchNode(r->left, x); // root is greater than key
	return searchNode(r->right, x); // root is smaller than key
}

void createTree(AVLTree& r) {
	do {
		int x;
		cout << "Enter a number(enter 0 to finish): ";
		cin >> x;
		if (x == 0) break;
		insertNode(r, x);
		cout << endl;
	} while (true);
}

void LNR (AVLTree r) {
	if (r) {
		LNR(r->left);
		cout << r->data << "  ";
		LNR(r->right);
	}
}