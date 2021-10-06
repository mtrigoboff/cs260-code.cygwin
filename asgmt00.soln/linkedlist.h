#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void add(char ch);
	bool find(char ch);
	bool del(char ch);

	friend std::ostream& operator<<(std::ostream& out, LinkedList& list);

private:
	struct Node
	{
		Node(char ch, Node* next);

		char	ch;
		Node*	next;
	};

	bool find(char ch, Node** nodePtr);

	Node*	first;
};

#endif // _LINKED_LIST_
