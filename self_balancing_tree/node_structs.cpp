typedef void* Node;

struct Node2 {
	Data		data[1];
	Node*		left;
	Node*		right;
};

struct Node3 {
	Data		data[2];
	Node*		left;
	Node*		middle;
	Node*		right;
};

struct Node4 {
	Data		data[3];
	Node*		left;
	Node*		midLeft;
	Node*		midRight;
	Node*		right;
};

// Node2 -> Node3
Node* n2;
Node* n3 = new Node3;

n3->data[0] = n2->data[0]
n3->left = n2->left;
n3->middle = n2->right;
n3->right = nullptr


enum class NodeType {NODE2, NODE3, NODE4};

struct Node {
	NodeType	type;
	Data		data[3];
	Node*		left;
	Node*		midLeft;
	Node*		midRight;
	Node*		right;
};
