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
	bool find(char ch) const;
	bool remove(char ch);
	int	length(void) const;

	friend std::ostream& operator<<(std::ostream& out, const List& list);

private:
	class Node
	{
	public:
		Node(char ch, Node* next) : ch{ch}, next{next} { }

		char	ch;
		Node*	next;
	};

	inline bool findPrev(char ch, Node*& prevRet) const;

	Node*	first;
};


#endif
