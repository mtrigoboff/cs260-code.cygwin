#include <iostream>
#include "bst.h"

using namespace std;

// This code displays binary search trees in an indented format:
//
//		R
//		|-A
//		  |
//		  |-F
//			|-B
//			  |
//			  |-C
//			|-L
//			  |-G
//			  |-M
//		|-T
//		  |-S
//		  |
//
// In the example above, R is the root node. R's left child is A. R's right child
// is T. A has no left child. A's right child is F. F's left child is B.
//
// R's right child is T. T's left child is S. T has no right child.

int main(int argc, char** argv)
{
    if (argc > 1)               // turn off cout
		std::cout.setstate(std::ios_base::badbit);

	BST*	bst = new BST();

	cout << "Binary Search Tree, reference version" << endl << endl;

	// insert bst
	bst->insert('R');
	bst->insert('A');
	bst->insert('F');
	bst->insert('L');
	bst->insert('B');
	bst->insert('C');
	bst->insert('T');
	bst->insert('G');
	bst->insert('M');
	cout << endl << "original BST" << endl << endl << *bst;

	bst->write("preorder.txt",  BST::TraverseOrder::PREORDER);
	bst->write("inorder.txt",   BST::TraverseOrder::INORDER);
	bst->write("postorder.txt", BST::TraverseOrder::POSTORDER);

	bst->read("preorder.txt");
	cout << endl << "read preorder" << endl << endl << *bst;

	bst->read("postorder.txt");
	cout << endl << "read postorder" << endl << endl << *bst;

	bst->read("inorder.txt");
	cout << endl << "read inorder" << endl << endl << *bst;

	bst->balance();
	cout << endl << "balanced" << endl << endl << *bst;

	bst->insert('S');
	cout << endl << "after inserting S" << endl << endl << *bst;

	cout << endl << "'S' is" << (bst->contains('S') ? " " : " not ") << "in the tree" << endl;
	cout << endl << "'X' is" << (bst->contains('X') ? " " : " not ") << "in the tree" << endl;

	bst->remove('S');
	cout << endl << "after removing S" << endl << endl << *bst;

	bst->remove('B');
	cout << endl << "after removing B" << endl << endl << *bst;

	bst->remove('F');
	cout << endl << "after removing F" << endl << endl << *bst;

	//test copy constructor
	BST *copy{new BST(*bst)};
	cout << endl << "copy of the BST " << endl << endl << *copy;

	delete copy;
	delete bst;

	cout << endl;
	return 0;
}
