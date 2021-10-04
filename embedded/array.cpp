#include "array.h"

using namespace std;

Array::Array(int size) :
	items{new Element[size]},
	size{size}
{
}

Array::~Array()
{
	delete[] items;
}

void Array::set(int index, char ch)
{
	items[index].ch = ch;
}

ostream& operator<<(ostream& out, Array& ar)
{
	for (int i = 0; i < ar.size; i++)
		out << ar.items[i];

	return out;
}

ostream& operator<<(ostream& out, Array::Element& el)
{
	out << el.ch;

	return out;
}

