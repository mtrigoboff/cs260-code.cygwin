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
	void addLast(char ch);
	bool find(char ch) const;
	bool remove(char ch);
	void empty();
	int	length(void) const;

	char& operator[](int index);

	friend std::ostream& operator<<(std::ostream& out, const List& list);

private:
	struct Node
	{
		Node(char ch, Node* next) : ch{ch}, next{next} { }

		char	ch;
		Node*	next;
	};

	inline bool findPrev(char ch, Node*& prevRet) const;

	Node*	first;
};


#endif
