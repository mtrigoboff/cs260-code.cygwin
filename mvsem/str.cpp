#include <cstring>
#include "str.h"

using namespace std;

int Str::nextID{1};

Str::Str() :
	chars{nullptr},
	instID{nextID++}
{
	cout << "default ctor(" << instID << ")" << endl;
}

Str::Str(char* chars) :
	chars{new char[strlen(chars) + 1]},
	instID{nextID++}
{
	cout << "ctor(" << instID << "): " << chars << endl;
	strcpy(this->chars, chars);
}

// copy constructor
Str::Str(const Str& str) :
	instID{nextID++}
{
	cout << "copy ctor(" << instID << " <- " << str.instID << "): " << str.chars << endl;
	if (str.chars != nullptr) {
		chars = new char[strlen(str.chars) + 1];
		strcpy(chars, str.chars);
		}
	else
		chars = nullptr;
}

// copy operator=
Str& Str::operator=(Str& rhs)
{
	delete[] chars;
	cout << "copy op=(" << instID << " <- " << rhs.instID << "): ";
	if (rhs.chars != nullptr) {
		cout << rhs.chars << endl;
		chars = new char[strlen(rhs.chars) + 1];
		strcpy(chars, rhs.chars);
		}
	else {
		cout << "nullptr" << endl;
		chars = nullptr;
		}
	return *this;
}

// move constructor
Str::Str(Str&& rval) :
	instID{nextID++}
{
	cout << "move ctor(" << instID << " <- " << rval.instID << "): " << rval.chars << endl;
	chars = rval.chars;
	rval.chars = nullptr;
}

// move operator=
Str& Str::operator=(Str&& rhs)
{
	cout << "move op=(" << instID << " <- " << rhs.instID << "): " << rhs.chars << endl;
	delete[] chars;
	chars = rhs.chars;
	rhs.chars = nullptr;
	return *this;
}

Str::~Str()
{
	cout << "dtor(" << instID << "): ";
	if (chars != nullptr)
		cout << chars;
	else
		cout << "nullptr";
	cout << endl;
	delete[] chars;
}

ostream& operator<<(ostream& out, Str& str)
{
	out << str.chars;
	return out;
}
