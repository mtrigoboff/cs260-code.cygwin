#include <cstring>
#include "string.h"

int		String::nextID{1};

String::String(char* str) :				// default constructor if called with no args
	str{str == nullptr ? nullptr : new char[strlen(str) + 1]},
	id{nextID++}
{
	if (str != nullptr)
		strcpy(this->str, str);
}

String::String(const String& src) :		// copy constructor
	id{nextID++}
{
	copy(src, false);
}

String::~String(void)					// destructor
{
	delete[] str;
}

String& String::operator=(const String& src)
{
	copy(src, true);
	return *this;
}

void String::copy(const String& src, bool deletePrevStr)
{
	if (this != &src) {
		if (deletePrevStr)
			delete[] str;
		if (src.str) {
			str = new char[strlen(src.str) + 1];
			strcpy(str, src.str);
			}
		else
			str = nullptr;
		}
}
