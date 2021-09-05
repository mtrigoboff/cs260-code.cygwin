#include <iostream>
#include "yesinitlists.h"

using namespace std;

// this constructor uses initializer lists
YesInitLists::YesInitLists(int first, int value, int last) :
	first{first},
	sequence{value},
	last{last}
{
	cout << "YesInitLists ctor: "
		 << first << ", " << value << ", " << last << endl;
}

YesInitLists::~YesInitLists(void)
{
}

ostream& operator<<(ostream& out, YesInitLists& yes)
{
	out << "YesInitLists["
		<< yes.first << ", "
		<< yes.sequence << ", "
		<< yes.last << "]";
	
	return out;
}
