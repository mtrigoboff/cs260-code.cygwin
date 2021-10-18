#include <iomanip>
#include "list.h"

using namespace std;

struct Node
{
	Node(char ch, Node* next) : ch{ch}, next{next} { }

	char	ch;
	Node*	next;
};

struct PrivateData
{
	PrivateData() : first{nullptr} {}

	Node*	first;
};

List::List(void) :
	privateData{new PrivateData()}
{
}

List::~List(void)
{
	empty();
	delete static_cast<PrivateData*>(privateData);
}

void List::addFirst(char ch)
{
	PrivateData*	pd{static_cast<PrivateData*>(this->privateData)};

	pd->first = new Node{ch, pd->first};
}

bool List::findPrev(char ch, void*& prevNode) const
{
	PrivateData*	pd{static_cast<PrivateData*>(this->privateData)};

	Node*			node{pd->first};
	Node*			prev{nullptr};

	while (node) {
		if (node->ch == ch) {
			prevNode = prev;
			return true;
			}
		prev = node;
		node = node->next;
	}
	return false;
}

bool List::addBefore(char before, char ch)
{
	PrivateData*	pd{static_cast<PrivateData*>(this->privateData)};

	Node*			prev;
	Node*			node;
	bool			foundPrev;

	foundPrev = findPrev(before, reinterpret_cast<void*&>(prev));
	if (foundPrev) {
		node = new Node(ch, nullptr);
		if (prev == nullptr) {
			node->next = pd->first;
			pd->first = node;
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

void List::addLast(char ch)
{
	PrivateData*	pd{static_cast<PrivateData*>(this->privateData)};

	Node*			node{pd->first};
	Node*			lastNode{nullptr};

	while (node) {
		lastNode = node;
		node = node->next;
		}
	lastNode->next = new Node(ch, nullptr);
}

bool List::find(char ch) const
{
	void*	unused;

	return findPrev(ch, unused);
}

bool List::remove(char ch)
{
	PrivateData*	pd{static_cast<PrivateData*>(this->privateData)};

	Node*			prev;
	Node*			node;
	bool			foundPrev;

	foundPrev = findPrev(ch, reinterpret_cast<void*&>(prev));
	if (foundPrev) {
		if (prev == nullptr) {
			node = pd->first;
			pd->first = node->next;
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

void List::empty()
{
	PrivateData*	pd{static_cast<PrivateData*>(this->privateData)};

	Node*			node{pd->first};
	Node*			nextNode;

	while (node) {
		nextNode = node->next;
		delete node;
		node = nextNode;
		}
	pd->first = nullptr;
}

int List::length(void) const
{
	PrivateData*	pd{static_cast<PrivateData*>(this->privateData)};

	Node*			node{pd->first};
	int				lgth{0};

	while (node) {
		lgth++;
		node = node->next;
		}
	return lgth;
}

char& List::operator[](int index)
{
	PrivateData*	pd{static_cast<PrivateData*>(this->privateData)};

	static char*	outOfRangeMsg{"index out of range"};

	Node*			node{pd->first};

	if (index < 0)
		throw outOfRangeMsg;
	for (int i = 0; i < index; i++) {
		if (node == nullptr)
			throw outOfRangeMsg;
		node = node->next;
		}
	return node->ch;
}

ostream& operator<<(ostream& out, const List& list)
{
	PrivateData*	pd{static_cast<PrivateData*>(list.privateData)};

	Node*			node{pd->first};
	bool			first{true};

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
