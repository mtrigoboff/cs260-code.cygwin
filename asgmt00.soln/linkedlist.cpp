#include <iostream>
#include "linkedlist.h"

using namespace std;

LinkedList::LinkedList() :
	first{nullptr}
{
}

LinkedList::~LinkedList()
{
	Node*	node;

	while (first) {
		node = first->next;
		delete first;
		first = node;
		}
}

LinkedList::Node::Node(char ch, Node* next) :
	ch{ch},
	next{next}
{
}

void LinkedList::add(char ch)
{
	first = new Node(ch, first);
}

bool LinkedList::find(char ch, Node** prevPtr)
{
	Node*	node{first};
	Node*	prev{nullptr};

	while (node) {
		if (node->ch == ch) {
			*prevPtr = prev;
			return true;
			}
		prev = node;
		node = node->next;
		}
	return false;
}

bool LinkedList::find(char ch)
{
	Node*	prev;

	return find(ch, &prev);
}

bool LinkedList::del(char ch)
{
	Node*	prev;
	Node*	node;

	if (find(ch, &prev)) {
		if (prev) {
			node = prev->next;
			prev->next = node->next;
			}
		else {
			node = first;
			first = node->next;
			}
		delete node;
		return true;
		}
	return false;
}

ostream& operator<<(ostream& out, LinkedList& list)
{
	LinkedList::Node*	node{list.first};

	out << "list contents: [";
	while (node) {
		out << node->ch;
		node = node->next;
		}
	out << ']';

	return out;
}

