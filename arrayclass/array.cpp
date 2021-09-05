#include "array.h"

using namespace std;

Array::Array(int size) :
	ar(new char[size]),
	size(size)
{
}

Array::~Array(void)
{
	delete[] ar;
}

char& Array::operator[](int index)
{
	// check whether index is in array bounds
	if (index < 0 || index >= size)
		throw new IndexOutOfBounds(index);

	// index in bounds, so OK to use it
	return ar[index];
}

ostream& operator<<(ostream& out, Array& a)
{
	bool	first = true;

	out << "[";
	for (int i = 0; i < a.size; i++) {
		if (first)
			first = false;
		else
			out << ", ";
		out << a.ar[i];
		}
	out << "]";
	return out;
}

ostream& operator<<(ostream& out, Array::IndexOutOfBounds *exc)
{
	out << "Array: index out of bounds (" << exc->index << ")";
	return out;
}
