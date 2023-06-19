#include <iostream>
#include "BinarySearchTree.h"
#include "AvlTree.h"

using namespace std;

int main(void) {
	//create trees for testing
	BinarySearchTree<int> bst;
	BinarySearchTree<int> emptybst;
	AvlTree<int> avl;
	AvlTree<int> emptyavl;

	//test case 1 and 2: when trees are empty
	cout << "test case 1 and 2 - when trees are empty: " << endl;
	cout << "\n";
	cout << "test case 1: "<< endl;
	cout << "Empty binary tree's height: " << emptybst.height() <<endl;
	cout << "\n";
	
	cout << "test case 2: " << endl;
	cout << "Empty AVL tree's height: " << emptyavl.height() << endl;
	cout << "\n";
	
	cout << "test case 3 - computing the height of a non-empty BST: " << endl;
	bst.insert(5); 
	bst.insert(8); 
	bst.insert(1);
	bst.insert(66); 
	bst.insert(44); 
	bst.insert(24);
	cout << "Height: " << bst.height() << endl;
	cout << "\n";
	
	cout << "test case 4 - computing the height of a non-empty AVL tree: " << endl;
	avl.insert(5); 
	avl.insert(8); 
	avl.insert(1);
	avl.insert(66); 
	avl.insert(44); 
	avl.insert(24);
	cout << "Height: " << avl.height() << endl;
	return 0;
}
