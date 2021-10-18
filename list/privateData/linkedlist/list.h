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
	bool findPrev(char ch, void*& prevNode) const;

	void* privateData;
};


#endif
