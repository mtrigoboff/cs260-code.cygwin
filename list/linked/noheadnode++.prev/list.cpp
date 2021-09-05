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

List::Node** List::findPrevPtr(char ch)
{
	Node*	node{first};
	Node*	prev{nullptr};

	while (node) {
		if (node->ch == ch) {
			if (prev == nullptr)
				return &first;
			else
				return &prev->next;
			}
		prev = node;
		node = node->next;
	}
	return nullptr;
}

bool List::addBefore(char before, char ch)
{
	Node**	prevPtr;
	Node*	node;

	if ((prevPtr = findPrevPtr(before)) != nullptr) {
		node = new Node(ch, nullptr);
		node->next = *prevPtr;
		*prevPtr = node;
		return true;
		}
	else
		return false;
}

bool List::find(char ch)
{
	return findPrevPtr(ch) != nullptr;
}

bool List::remove(char ch)
{
	Node**	prevPtr;
	Node*	node;

	if ((prevPtr = findPrevPtr(ch)) != nullptr) {
		node = *prevPtr;
		*prevPtr = node->next;
		delete node;
		return true;
		}		
	else
		return false;
}

int List::length(void)
{
	Node*	node{first};
	int		lgth{0};

	while (node) {
		lgth++;
		node = node->next;
		}
	return lgth;
}

ostream& operator<<(ostream& out, List& list)
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
