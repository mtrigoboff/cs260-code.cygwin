#include <iomanip>
#include "list.h"

using namespace std;

struct Node
{
	Node(char ch, Node* next) : ch{ch}, next{next} { }

	char	ch;
	Node*	next;
};

struct InstanceData
{
	InstanceData() : first{nullptr} {}

	bool findPrev(char ch, void*& prevNode) const;

	Node*	first;
};

bool InstanceData::findPrev(char ch, void*& prevNode) const
{
	Node*			node{first};
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

List::List(void) :
	instanceData{new InstanceData()}
{
}

List::~List(void)
{
	empty();
	delete static_cast<InstanceData*>(instanceData);
}

void List::addFirst(char ch)
{
	InstanceData*	id{static_cast<InstanceData*>(this->instanceData)};

	id->first = new Node{ch, id->first};
}

bool List::addBefore(char before, char ch)
{
	InstanceData*	id{static_cast<InstanceData*>(this->instanceData)};

	Node*			prev;
	Node*			node;
	bool			foundPrev;

	foundPrev = id->findPrev(before, reinterpret_cast<void*&>(prev));
	if (foundPrev) {
		node = new Node(ch, nullptr);
		if (prev == nullptr) {
			node->next = id->first;
			id->first = node;
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
	InstanceData*	id{static_cast<InstanceData*>(this->instanceData)};

	Node*			node{id->first};
	Node*			lastNode{nullptr};

	while (node) {
		lastNode = node;
		node = node->next;
		}
	lastNode->next = new Node(ch, nullptr);
}

bool List::find(char ch) const
{
	InstanceData*	id{static_cast<InstanceData*>(this->instanceData)};
	void*			unused;

	return id->findPrev(ch, unused);
}

bool List::remove(char ch)
{
	InstanceData*	id{static_cast<InstanceData*>(this->instanceData)};

	Node*			prev;
	Node*			node;
	bool			foundPrev;

	foundPrev = id->findPrev(ch, reinterpret_cast<void*&>(prev));
	if (foundPrev) {
		if (prev == nullptr) {
			node = id->first;
			id->first = node->next;
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
	InstanceData*	id{static_cast<InstanceData*>(this->instanceData)};

	Node*			node{id->first};
	Node*			nextNode;

	while (node) {
		nextNode = node->next;
		delete node;
		node = nextNode;
		}
	id->first = nullptr;
}

int List::length(void) const
{
	InstanceData*	id{static_cast<InstanceData*>(this->instanceData)};

	Node*			node{id->first};
	int				lgth{0};

	while (node) {
		lgth++;
		node = node->next;
		}
	return lgth;
}

char& List::operator[](int index)
{
	InstanceData*	id{static_cast<InstanceData*>(this->instanceData)};

	static char*	outOfRangeMsg{"index out of range"};

	Node*			node{id->first};

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
	InstanceData*	id{static_cast<InstanceData*>(list.instanceData)};

	Node*			node{id->first};
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
