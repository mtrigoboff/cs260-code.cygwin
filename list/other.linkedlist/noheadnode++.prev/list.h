#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>

class List
{
public:
	List(void);
	~List(void);
	void addFirst(char ch);
	bool addBefore(char before, char ch);
	bool find(char ch);
	bool remove(char ch);
	int	length(void);

	friend std::ostream& operator<<(std::ostream& out, List& list);

private:
	class Node
	{
	public:
		Node(char ch, Node* next) : ch{ch}, next{next} { }

		char	ch;
		Node*	next;
	};

	inline Node** findPrevPtr(char ch);

	Node*	first;
};


#endif
