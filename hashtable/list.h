#ifndef _LIST_H_
#define _LIST_H_

#include <ostream>

class List
{
public:
	List(void);
	~List(void);
	int* add(const char* const key, int value);
	bool find(const char* const key, int** value = nullptr) const;
	bool remove(const char* const key);
	int	length(void) const;

	friend std::ostream& operator<<(std::ostream& out, List& list);

private:
	struct Node
	{
		Node(const char* const key, int value);
		~Node(void);

		char	*key;
		int		value;
		Node	*next;
	};

	bool find(const char* const key, Node** nodePtr = nullptr, Node** prevNodePtr = nullptr) const;

	Node*	first;
	Node*	last;
	int		lgth;
};


#endif
