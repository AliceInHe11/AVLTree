#include<iostream>

using namespace std;

struct Node {
	Node* left;
	Node* right;
	int data;
	int height;
};
typedef Node* Nodeptr;
typedef Node* AVLTree;

void initTree (AVLTree& r);
Nodeptr makeNode (int x);
int height (Nodeptr r);
void rotateRight (AVLTree& r);
void rotateLeft (AVLTree& r);
void rotateRightLeft (AVLTree& r);
void rotateLeftRight (AVLTree& r);
void balanceLeft (AVLTree& r);
void balanceRight (AVLTree& r);
void insertNode(AVLTree& r, int a);
void createTree (AVLTree &r);
void LNR( AVLTree r);