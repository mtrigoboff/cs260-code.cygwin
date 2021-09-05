#ifndef _ARRAYLIST_H_
#define _ARRAYLIST_H_

#include <iostream>
#include <string>

// class definition
template <typename ITEM_TYPE>
class ArrayList
{
public:
	ArrayList(const int capacity = 10);
	virtual ~ArrayList(void);
	
	int size(void) const;
	bool add(const ITEM_TYPE& item);
	ITEM_TYPE& operator[] (const int index) const;

	// to be used as a thrown exception
	class ArrayListException
	{
	private:
		std::string	what;

	public:
		ArrayListException(std::string what) : what{what} { };

		friend std::ostream& operator<<(std::ostream& out, ArrayListException& e)
		{
			out << "ArrayListException: " << e.what << std::endl;
			return out;
		}
	};

	// iterator-related

	class iterator
	{
	public:
		iterator(ITEM_TYPE* ptr) : ptr{ptr}	 { }
		iterator operator++()	 /* prefix */{ ptr++; return *this; }
		iterator operator++(int) /* suffix */{ iterator it = *this; ptr++; return it; }
		ITEM_TYPE& operator*()				 { return *ptr; }
		ITEM_TYPE* operator->()				 { return ptr; }
		bool operator==(const iterator& rhs) { return ptr == rhs.ptr; }
		bool operator!=(const iterator& rhs) { return ptr != rhs.ptr; }

	private:
		ITEM_TYPE	*ptr;
	};

	// In the following two functions, it is not necessary to directly invoke
	// the iterator constructor. The compiler is apparently smart enough to know
	// that it needs to be done without specifying it explicitly.
	iterator begin()	{ return iterator{&array[0]}; }
	iterator end()		{ return iterator{&array[next]}; }

private:
	ITEM_TYPE	*array;
	int			capacity;
	int			next;
	int			growthFactor;

};

#include "arraylist.cpp"
// Needed to avoid link errors. The code in ArrayList.cpp will be compiled when
// ArrayList.h is #included and the file that #includes it requests instantiation
// by specifying a particular type specialization, e.g. ArrayList<int>.

#endif // _ARRAYLIST_H_
