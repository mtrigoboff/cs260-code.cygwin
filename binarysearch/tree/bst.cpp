#include "bst.h"

using namespace std;

BST::BST() : root{nullptr}, size{0}
{
}

// copy constructor
BST::BST(const BST& bst) : root{nullptr}, size{bst.size}
{
	copyTree(root, bst.root);
}

const BST& BST::operator=(const BST& bst)
{
	// only do something if not assigning to same instance (e.g. x = x)
	if (this != &bst) {
		//release dynamically allocated memory held by current instance
		destroyTree();

		//copy the tree
		size = bst.size;
		copyTree(root, bst.root);
		}
	return *this;
}

void BST::copyTree(Node*& newNode, Node* node)
{
	if (node) {
		newNode = new Node(node->ch);
		copyTree(newNode->left, node->left);
		copyTree(newNode->right, node->right);
		}
	else
		newNode = nullptr;
}

BST::~BST()
{
	destroyTree();
}

void BST::destroyTree()
{
	postorder(root, &BST::deallocateNode);
	root = nullptr;
	size = 0;
}

void BST::deallocateNode(Node *node)
{
	delete node;
}

void BST::insert(const char ch)
{
	insert(root, ch);
}

void BST::insert(Node*& node, const char ch)
{
	if (! node) {
		node = new Node(ch);
		size++;
		}
	else if (ch < node->ch)
		insert(node->left, ch);
	else
		insert(node->right, ch);
}

bool BST::remove(char ch)
{
	return remove(root, ch);
}

bool BST::remove(Node*& node, char ch)
{
	if (! node)
		return false;
	else if (ch == node->ch) {
		deleteNode(node);
		return true;
		}
	else if (ch < node->ch)
		return remove(node->left, ch);
	else
		return remove(node->right, ch);
}

void BST::deleteNode(Node*& target)
{
	Node*	temp;

	// a leaf
	if (! target->left && ! target->right) {
		delete target;
		target = nullptr;
		}
	// no left child
	else if (! target->left) {
		temp = target;
		target = target->right;
		delete temp;
		}
	// no right child
	else if (! target->right) {
		temp = target;
		target = target->left;
		delete temp;
		}
	// two children
	else {
		//find the inorder successor
		Node	*prev{nullptr};
		Node	*curr{target->right};

		while (curr->left) {
			prev = curr;
			curr = curr->left;
			}

		// copy data at curr (the inorder successor) into target
		target->ch = curr->ch;

		// disconnect the inorder successor
		if (! prev)
			target->right = curr->right;
		else
			prev->left = curr->right;	// inorder successor could have right child

		// delete the inorder successor
		delete curr;
		}
	size--;
}

bool BST::contains(char ch) const
{
	return contains(*root, ch);
}

bool BST::contains(Node& node, char ch) const
{
	if(ch == node.ch)
		return true;
	else if(ch < node.ch)
		return node.left  ? contains(*node.left, ch)  : false;
	else
		return node.right ? contains(*node.right, ch) : false;
}

int BST::getSize(void) const
{
	return size;
}

void BST::balance(void)
{
	char*	fileName{"balance.txt"};
	int		treeSize{size};

	write(fileName, BST::TraverseOrder::INORDER);
	destroyTree();
	file.open(fileName, ios::in);
	balance(root, treeSize);
	file.close();
}

void BST::balance(Node*& nodePtr, int nNodes)
{
	if (nNodes > 0) {
		nodePtr = new Node();
		balance(nodePtr->left, nNodes / 2);
		readNode(nodePtr);
		balance(nodePtr->right, (nNodes - 1) / 2);
		}
}

bool BST::read(char* fileName)
{
	char	ch;

	destroyTree();
	file.open(fileName, ios::in);
	if (! file.is_open())
		return false;
	for (;;) {
		file.read(&ch, 1);
		if (file.eof())
			break;
		if (ch == '\n')
			continue;
		insert(root, ch);
		}
	file.close();
	return true;
}

bool BST::write(char* fileName, TraverseOrder order)
{
	// fn ptrs required to be in same order as BST::TraverseOrder
	static const BST::TraverseFn traverseFns[]
		= {&BST::preorder, &BST::inorder, &BST::postorder};

	file.open(fileName, ios::out);
	if (! file.is_open())
		return false;
	(this->*traverseFns[static_cast<int>(order)])
		(root, &BST::writeNode);
	file.write("\n", 1);	// append newline so that cat will work properly
	file.close();
	return true;
}

void BST::readNode(Node* node)
{
	file.read(&node->ch, 1);
}

void BST::writeNode(Node* node)
{
	file.write(&node->ch, 1);
}

void BST::preorder(Node* node, NodeFn nfn)
{
	if (node) {
		(this->*nfn)(node);
		preorder(node->left, nfn);
		preorder(node->right, nfn);
		}
}

void BST::inorder(Node* node, NodeFn nfn)
{
	if (node) {
		inorder(node->left, nfn);
		(this->*nfn)(node);
		inorder(node->right, nfn);
		}
}

void BST::postorder(Node* node, NodeFn nfn)
{
	if (node) {
		postorder(node->left, nfn);
		postorder(node->right, nfn);
		(this->*nfn)(node);
		}
}

static void printLevelSpacers(ostream& out, int spacers)
{
	for (int i = 0; i < spacers; i++)
		out << "  ";
}

void BST::display(ostream& out, Node* node, int level) const
{
	if (node) {
		printLevelSpacers(out, level - 1);
		if (level)
			out << "|-";
		out << node->ch << endl;
		if (node->left || node->right) {
			if (node->left)
				display(out, node->left, level + 1);
			else {
				printLevelSpacers(out, level);
				out << '|' << endl;
				}
			if (node->right)
				display(out, node->right, level + 1);
			else {
				printLevelSpacers(out, level);
				out << '|' << endl;
				}
			}
		}
}

ostream& operator<<(ostream& out, BST& bst)
{
	bst.display(out, bst.root, 0);
	return out;
}
