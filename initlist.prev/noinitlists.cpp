#include <iostream>
#include "noinitlists.h"

using namespace std;

// this constructor does not use initializer lists
NoInitLists::NoInitLists(int first, int value, int last)
{
	// Sequence default ctor has already been called.
	cout << "NoInitLists ctor: "
		 << first << ", " << value << ", " << last << endl;
	this->first = first;
	this->last = last;
	cout << *this << endl;
	sequence.setValue(value);
}

NoInitLists::~NoInitLists(void)
{
}

ostream& operator<<(ostream& out, NoInitLists& no)
{
	out << "NoInitLists["
		<< no.first << ", "
		<< no.sequence << ", "
		<< no.last << "]";
	
	return out;
}
