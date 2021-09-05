#include <cassert>
#include <cstring>
#include <iomanip>
#include "list.h"

using namespace std;

List::List(void) :
	first{nullptr},
	last{nullptr},
	lgth{0}
{
}

List::~List(void)
{
	Node*	node{first};
	Node*	nextNode;

	while (node) {
		nextNode = node->next;
		delete node;
		node = nextNode;
		}
}

List::Node::Node(char* key, int value) :
	key{new char[strlen(key) + 1]},
	value{value},
	next{nullptr}
{
	strcpy(this->key, key);
}

List::Node::~Node(void)
{
	delete[] key;
}

int* List::add(char* key, int value)
{
	Node*	newNode{new Node(key, value)};

	if (last == nullptr)
		first = last = newNode;
	else {
		last->next = newNode;
		last = newNode;
		}
	lgth++;
	return &newNode->value;
}

int List::find(char* key, int** value) const
{
	Node*	node{first};
	int		n{0};

	while (node) {
		if (! strcmp(node->key, key)) {
			if (value)
				*value = &node->value;
			return n;
			}
		node = node->next;
		n++;
		}
	return -1;
}

void List::remove(int index)
{
	Node*	node{first};
	Node*	prev;
	Node*	remNode;
	int		i{0};

	while (node) {
		if (i == index) {
			if (node == first) {
				remNode = node;
				first = remNode->next;
				}
			else {
				remNode = node;
				prev->next = node->next;
				}
			delete remNode;
			lgth--;
			return;
			}
		prev = node;
		node = node->next;
		i++;
		}
	// Thanks to Fall 2016 student Hang Li for pointing out
	// that the lgth-- statement needed to be where it now
	// is instead of where this comment is.
}

int List::length(void) const
{
	return lgth;
}

ostream& operator<<(ostream& out, List& list)
{
	List::Node*	node{list.first};
	bool		first{true};
	int			nNodes{0};

	if (! node)
		out << "---";
	else
		while (node) {
			if (first)
				first = false;
			else
				out << ", ";
			out << "(" << node->key << ", " << node->value << ")";
			node = node->next;
			nNodes++;
			}
	assert(nNodes == list.lgth);
	return out;
}
