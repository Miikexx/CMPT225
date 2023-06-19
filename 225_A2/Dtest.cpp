#include <iostream>
#include "BinarySearchTree.h"
#include "AvlTree.h"

using namespace std;

int main(void)
{
	BinarySearchTree<int> bst;
	AvlTree<int> avl;
	// BST -----------------------------------------
	//constructing bst:
	bst.insert(5); 
	bst.insert(8); 
	bst.insert(1);
	bst.insert(66); 
	bst.insert(44); 
	bst.insert(24);
	
	//list elements in the tree:
	cout << "The keys in the binary search tree are: 5,8,1,66,44,22. " << endl;
	cout <<"\n";
	
	//look for element within the tree
	cout << "Test case 1-1 : when the target element is in the tree: " << endl;
	cout << "the depth of element 44: " << bst.depth(44) << endl;
	cout <<"\n";
	
	// returning the search depth when the element isn't there 
	cout << "Test case 1-2: when the element is not in the tree (expected to return the depth of the search within the bst): " << endl;
	cout << "Depth when looking for 20:" << bst.depth(20) << endl;
	cout << "\n";
	
	// AVL ------------------------------------------
	//constructing avl tree:
	avl.insert(5); 
	avl.insert(8); 
	avl.insert(1);
	avl.insert(66); 
	avl.insert(44); 
	avl.insert(24);
	
	//list elements in the tree:
	cout << "The keys in the Avl tree are: 5,8,1,66,44,22. " << endl;
	cout << "\n";
	//look for element within the tree
	cout << "Test case 2-1 : when the target element is in the tree: " << endl;
	cout << "the depth of element 44: " << avl.depth(44) << endl;
	cout << "\n";
	
	// returning the search depth when the element isn't there 
	cout << "Test case 2-2: when the element is not in the tree (expected to return the depth of the search within the avl tree): " << endl;
	cout << "Depth when looking for 20:" << avl.depth(20) << endl;
	cout << "\n";
	
	return 0;
}
