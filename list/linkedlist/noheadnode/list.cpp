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

bool List::findPrev(char ch, Node*& prevRet) const
{
	Node*	node{first};
	Node*	prev{nullptr};

	while (node) {
		if (node->ch == ch) {
			prevRet = prev;
			return true;
			}
		prev = node;
		node = node->next;
	}
	return false;
}

bool List::addBefore(char before, char ch)
{
	Node*	prev;
	Node*	node;

	if (findPrev(before, prev)) {
		node = new Node(ch, nullptr);
		if (prev == nullptr) {
			node->next = first;
			first = node;
			}
		else {
			node->next = prev->next;
			prev->next = node;
			}
		return true;
		}
	else
		return false;
}

bool List::find(char ch) const
{
	Node*	node;

	return findPrev(ch, node);
}

bool List::remove(char ch)
{
	Node*	prev;
	Node*	node;

	if (findPrev(ch, prev)) {
		if (prev == nullptr) {
			node = first;
			first = node->next;
			}
		else {
			node = prev->next;
			prev->next = node->next;
			}
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
