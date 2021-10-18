#include <iomanip>
#include "list.h"

using namespace std;

List::List(void) :
	head{new Node{'!', nullptr}}
{
}

List::~List(void)
{
	Node*	node{head};
	Node*	nextNode;

	do {
		nextNode = node->next;
		delete node;
		node = nextNode;
		}
	while (node);
}

void List::addFirst(char ch)
{
	head->next = new Node{ch, head->next};
}

bool List::findPrev(char ch, Node*& prevRet) const
{
	Node*	node{head->next};
	Node*	prev{head};

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
		node = new Node(ch, prev->next);
		prev->next = node;
		return true;
		}
	else
		return false;
}

bool List::find(char ch) const
{
	Node*	prev;

	return	findPrev(ch, prev);
}

bool List::remove(char ch)
{
	Node*	prev;
	Node*	node;

	if (findPrev(ch, prev)) {
		node = prev->next;
		prev->next = node->next;
		delete node;
		return true;
		}
	else
		return false;
}

int List::length(void) const
{
	Node*	node{head->next};
	int		lgth{0};

	while (node) {
		lgth++;
		node = node->next;
		}
	return lgth;
}

ostream& operator<<(ostream& out, const List& list)
{
	List::Node*	node{list.head->next};
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
