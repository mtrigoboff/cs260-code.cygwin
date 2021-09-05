#ifndef _BST_H_
#define _BST_H_

#include <ostream>
#include <fstream>

class BST
{
public:
	BST();
	BST(const BST& bst);
	~BST();

	const BST& operator=(const BST& bst);

	void insert(const char ch);
	bool remove(char ch);
	bool contains(char ch) const;
	int getSize(void) const;
	void balance(void);

	// traverseFns order in BST::write required to be same as this enum
	enum class TraverseOrder {PREORDER, INORDER, POSTORDER};

	bool read(char* fileName);
	bool write(char* fileName, TraverseOrder order);

	friend std::ostream& operator<<(std::ostream& out, BST& bst);

private:
	struct Node
	{
		Node(const char ch) : ch(ch), left(nullptr), right(nullptr) { }
		Node(void) : ch('\0'), left(nullptr), right(nullptr) { }

		char	ch;
		Node*	left;
		Node*	right;
	};

	// defines datatype NodeFn, which is a pointer to a member function
	// of BST that returns void and takes one argument, a pointer to Node
	typedef void (BST::*NodeFn)(Node* node);
	void readNode(Node* node);
	void writeNode(Node* node);
	void deallocateNode(Node* node);

	typedef void (BST::*TraverseFn)(Node* node, NodeFn nfn);
	void preorder(Node* node, NodeFn nfn);
	void inorder(Node* node, NodeFn nfn);
	void postorder(Node* node, NodeFn nfn);

	Node*			root;	
	int				size;
	std::fstream	file;
	
	void insert(Node*& node, const char ch);
	bool contains(Node& node, char ch) const;
	bool remove(Node*& node, char ch);
	void deleteNode(Node*& target);
	void balance(Node*& nodePtr, int nNodes);
	void display(std::ostream& out, Node* node, int level) const;
	void destroyTree();
	void copyTree(Node*& newNode, Node* node);
};

#endif
