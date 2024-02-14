#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <ostream>

// Manages an array of chars. Does bounds checking on indexes.

class Array
{
public:
	Array(int size);				// create an array with 'size' elements
	~Array(void);
	char& operator[](int index);	// Why does this return char& and not just char?

	class IndexOutOfBounds
	{
	public:
		IndexOutOfBounds(int index) : index(index) { }

		friend std::ostream& operator<<(std::ostream& out, IndexOutOfBounds *exc);

	private:
		int index;
	};

	friend std::ostream& operator<<(std::ostream& out, Array& a);

private:
	char*	ar;
	int		size;
};

#endif
