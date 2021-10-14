#include <iomanip>
#include "list.h"

using namespace std;

List::List(void) :
	first{nullptr}
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

void List::addFirst(char ch)
{
	first = new Node{ch, first};
}

bool List::findPrevPtr(char ch, Node*** prevPtrRet) const
{
	Node*	node{first};
	Node**	prevPtr{const_cast<Node**>(&first)};

	while (node) {
		if (node->ch == ch) {
			*prevPtrRet = prevPtr;
			return true;
			}
		prevPtr = &node->next;
		node = node->next;
	}
	return false;
}

bool List::addBefore(char before, char ch)
{
	Node**	prevPtr;
	Node*	node;

	if (findPrevPtr(before, &prevPtr)) {
		node = new Node(ch, *prevPtr);
		*prevPtr = node;
		return true;
		}
	else
		return false;
}

bool List::find(char ch) const
{
	Node**	nodePtr;

	return findPrevPtr(ch, &nodePtr);
}

bool List::remove(char ch)
{
	Node**	prevPtr;
	Node*	node;

	if (findPrevPtr(ch, &prevPtr)) {
		node = *prevPtr;
		*prevPtr = node->next;
		delete node;
		return true;
		}		
	else
		return false;
}

int List::length(void) const
{
	Node*	node{first};
	int		lgth{0};

	while (node) {
		lgth++;
		node = node->next;
		}
	return lgth;
}

ostream& operator<<(ostream& out, const List& list)
{
	List::Node*	node{list.first};
	bool		first{true};

	out << "List: (" << setw(2) << list.length() << " elements) [";
	while (node) {
		if (first)
			first = false;
		else
			out << ", ";
		out << node->ch;
		node = node->next;
		}
	out << "]" << endl;
	return out;
}
