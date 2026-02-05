#ifndef _LIST_PRIV_H_
#define _LIST_PRIV_H_

#include <iostream>

class ListPriv
{
public:
	ListPriv(void);
	~ListPriv(void);
	void addFirst(char ch);
	bool addBefore(char before, char ch);
	void addLast(char ch);
	bool find(char ch) const;
	bool remove(char ch);
	void empty();
	int	length(void) const;

	char& operator[](int index);

	friend std::ostream& operator<<(std::ostream& out, const ListPriv& listPriv);

private:
	void	expandIfNeeded(void);
	bool	findIndex(char ch, int& index) const;

	char*	listArray;
	int		arraySize;
	int		nItems;
};


#endif
