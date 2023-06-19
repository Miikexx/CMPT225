#include <iostream>
#include "BinarySearchTree.h"
#include "AvlTree.h"

using namespace std;

int main(void)
{
	
	BinarySearchTree<int> bst;
	AvlTree<int> avl;
	
	cout << "For the Binary search tree:" << endl;
	//test case 1 for bst:
	cout << "BST test case 1: " << endl;
	bst.insert(8);
	bst.insert(5);
	bst.insert(2);
	bst.insert(6);
	bst.insert(9);
	bst.insert(0);
	bst.insert(3);

	bst.displayLinks();
	cout << "\n" ;
	
	//test case 2 for bst:
	BinarySearchTree<int> bst2;
	cout <<"BST test case 2: " << endl;
	for(int i =1; i < 6; i++)
	{
		bst2.insert(i);
	}
	bst2.displayLinks();
	cout << "\n" ;
	
	// AVL tree
	cout << "For the AVL tree:" << endl;
	cout << "Avl tree test case 1: " << endl;
	avl.insert(8);
	avl.insert(5);
	avl.insert(2);
	avl.insert(6);
	avl.insert(9);
	avl.insert(0);
	avl.insert(3);
	
	avl.displayLinks();
	
	//test case 2 for avl tree:
	AvlTree<int> avl2;
	cout << "\n" ;
	cout <<"Avl tree test case 2: " << endl;
	for(int i =1; i < 6; i++)
	{
		avl2.insert(i);
	}
	avl2.displayLinks();
	
}
