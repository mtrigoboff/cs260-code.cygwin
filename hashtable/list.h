#ifndef _LIST_H_
#define _LIST_H_

#include <ostream>

class List
{
public:
	List(void);
	~List(void);
	int* add(char* key, int value);
	int find(char* key, int** value) const;
	void remove(int index);
	// void changeValue(int index, int newValue);
	int	length(void) const;

	friend std::ostream& operator<<(std::ostream& out, List& list);

private:
	class Node
	{
	public:
		Node(char *key, int value);
		~Node(void);
		char	*key;
		int		value;
		Node	*next;
	};

	Node*	first;
	Node*	last;
	int		lgth;
};


#endif
