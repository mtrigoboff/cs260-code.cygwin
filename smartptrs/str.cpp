#include <cstring>
#include "str.h"

using namespace std;

int Str::nextID{1};

Str::Str(char* chars) :
	chars{new char[strlen(chars) + 1]}
{
	cout << "Str ctor \"" << chars << "\"" << endl;
	strcpy(this->chars, chars);
}

Str::~Str()
{
	cout << "Str dtor ";
	if (chars != nullptr)
		cout << "\"" << chars << "\"";
	else
		cout << "null string";
	cout << endl;
	delete[] chars;
}

ostream& operator<<(ostream& out, Str* str)
{
	if (str == nullptr)
		out << "nullptr";
	else
		out << "\"" << (str->chars == nullptr ? "null string" : str->chars) << "\"";
	return out;
}
