#include <iostream>
#include "BST.h"
using namespace std;
int main() {
	BST tree;
	tree.insert(50);
	tree.insert(30);
	tree.insert(20);
	tree.insert(40);
	tree.insert(70);
	tree.insert(60);
	tree.insert(80);
	cout << "Inorder traversal: ";
	tree.inorder();
	cout << endl;
	int key = 40;
	if (tree.search(key)) {
		cout << key << " found in the tree." << endl;
	}
	else {
		cout << key << " not found in the tree." << endl;
	}
	key = 90;
	if (tree.search(key)) {
		cout << key << " found in the tree." << endl;
	}
	else {
		cout << key << " not found in the tree." << endl;
	}
	tree.DeleteNode(20);
	cout << "Inorder traversal after deleting 20: ";
	tree.inorder();
	cout << endl;
	return 0;
}