#include <cstring>
#include "string_shallow.h"

int		StringShallow::nextID{1};

StringShallow::StringShallow(char *str) :				// default constructor if called with no args
	str{str == nullptr ? nullptr : new char[strlen(str) + 1]},
	id{nextID++}
{
	if (str != nullptr)
		strcpy(this->str, str);
}

StringShallow::~StringShallow(void)						// destructor
{
	delete[] str;
}
