#include "arraylist.h"

ArrayList::ArrayList(const int capacity) :
	array{new char[capacity]},
	capacity{capacity},
	next{0}
{
}

ArrayList::~ArrayList(void)
{
	delete[] array;
}

int ArrayList::size(void) const
{
	return next;
}

bool ArrayList::add(const char& item)
{
	if (next >= capacity)						// array full
		throw ArrayListException("array full");
	array[next++] = item;
	return true;
}

char& ArrayList::operator[] (const int index) const
{
	if (index >= 0 && index < next) {			// index in range?
		return array[index];					// return value
		}
	else
		throw ArrayListException("index [" + std::to_string(index) + "] out of bounds");
}
