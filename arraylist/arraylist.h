#ifndef _ARRAYLIST_H_
#define _ARRAYLIST_H_

#include <iostream>
#include <string>

// class definition
class ArrayList
{
public:
	ArrayList(const int capacity = 3);
	virtual ~ArrayList(void);
	
	int size(void) const;
	bool add(const char& item);
	char& operator[] (const int index) const;

	// to be used as a thrown exception
	class ArrayListException
	{
	private:
		std::string	what;

	public:
		ArrayListException(std::string what) : what{what} { };

		friend std::ostream& operator<<(std::ostream& out, ArrayListException& e)
		{
			out << "ArrayListException: " << e.what;
			return out;
		}
	};

	// iterator-related

	class iterator
	{
	public:
		iterator(char* ptr) : ptr{ptr}	 { }
		iterator operator++()	 /* prefix */{ ptr++; return *this; }
		iterator operator++(int) /* suffix */{ iterator it = *this; ptr++; return it; }
		char& operator*()				 { return *ptr; }
		char* operator->()				 { return ptr; }
		bool operator==(const iterator& rhs) { return ptr == rhs.ptr; }
		bool operator!=(const iterator& rhs) { return ptr != rhs.ptr; }

	private:
		char	*ptr;
	};

	// In the following two functions, it is not necessary to directly invoke
	// the iterator constructor. The compiler is apparently smart enough to know
	// that it needs to be done without specifying it explicitly.
	iterator begin()	{ return iterator{&array[0]}; }
	iterator end()		{ return iterator{&array[next]}; }

private:
	char	*array;
	int			capacity;
	int			next;
	int			growthFactor;

};

#endif // _ARRAYLIST_H_
