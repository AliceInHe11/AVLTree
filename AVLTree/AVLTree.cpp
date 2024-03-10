#include"Header.h"

int main() {
	AVLTree test;

	initTree(test);
	createTree(test);
	cout << "Data: ";
	LNR(test);

	return 0;
}

