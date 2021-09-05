#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>

class List
{
public:
	List(void);
	~List(void);
	void addFirst(char ch);
	bool getFirst(char& ch);
	bool addBefore(char before, char ch);
	bool find(char ch);
	bool remove(char ch);
	bool removeFirst(char& ch);
	int	length(void);

	class Iterator
	{
	public:
		bool getNext(char& ch);

	private:
		Iterator(List& list);
		// constructor is private so that you can only get an instance
		// of Iterator by calling getIterator(), defined below

		List&	list;
		int		next;

		friend class List;
	};

	Iterator *getIterator(void) { return new Iterator(*this); }

	friend std::ostream& operator<<(std::ostream& out, List& list);
	friend std::ostream& operator<<(std::ostream& out, List* list);

private:
	void	expandIfNeeded(void);
	bool	findIndex(char ch, int& index);

	char*	listArray;
	int		arraySize;
	int		nextIndex;
};


#endif
