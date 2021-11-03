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

List::Node::Node(const char* const key, int value) :
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

int* List::add(const char* const key, int value)
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

// private overload
bool List::find(const char* const key, Node** nodePtr, Node** prevNodePtr) const
{
	Node*	prev{nullptr};
	Node*	node{first};

	while (node) {
		if (! strcmp(node->key, key)) {
			if (prevNodePtr)
				*prevNodePtr = prev;
			if (nodePtr)
				*nodePtr = node;
			return true;
			}
		prev = node;
		node = node->next;
		}
	return false;
}

// public overload
bool List::find(const char* const key, int** valuePtr) const
{
	Node*	node;

	if (find(key, &node)) {
		if (valuePtr)
			*valuePtr = &node->value;
		return true;
		}
	else
		return false;
}

bool List::remove(const char* const key)
{
	Node*	prev;
	Node*	node;

	if (find(key, &node, &prev)) {
		if (node == first)
			first = node->next;
		else
			prev->next = node->next;
		delete node;
		lgth--;
		return true;
		}
	else
		return false;
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
