#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>

class Array
{
public:

	Array(int size);
	~Array();

	void set(int index, char ch);

	friend std::ostream& operator<<(std::ostream& out, Array& ar);

private:
	
	struct Element
	{
		Element() : ch{'!'} {}

		char	ch;
	};

	Element*	items;
	int			size;

	friend std::ostream& operator<<(std::ostream& out, Element& el);
};

#endif //  _ARRAY_H_
