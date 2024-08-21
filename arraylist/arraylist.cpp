#include "arraylist.h"

ArrayList::ArrayList(const int capacity) :
	ar{new char[capacity]},
	capacity{capacity},
	next{0}
{
}

ArrayList::~ArrayList(void)
{
	delete[] ar;
}

int ArrayList::size(void) const
{
	return next;
}

void ArrayList::add(const char& item)
{
	if (next >= capacity)						// array full
		throw ArrayListException("array full");
	ar[next++] = item;
}

char& ArrayList::operator[] (const int index) const
{
	if (index >= 0 && index < next)				// index in range?
		return ar[index];						// return value
	else
		throw ArrayListException("index [" + std::to_string(index) + "] out of bounds");
}
