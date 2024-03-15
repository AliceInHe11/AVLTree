#include"Header.h"

int main() {
	AVLTree test;

	initTree(test);
	createTree(test);
	cout << "Data: ";
	LNR(test);

	int key = 10;
	Nodeptr p = searchNode(test, key);
	if (p == NULL)
		cout << "\n"<<key<<" not found.";
	else 
		cout << "\n"<<key<<" found.";

	deleteNode(test, 4);
	cout << endl;
	LNR(test);

	return 0;
}

