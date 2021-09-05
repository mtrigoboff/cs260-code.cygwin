#include <iostream>
#include "sequence.h"

using namespace std;

Sequence::Sequence(void) :
	before{-1},
	value{0},
	after{1}
{
	cout << "Sequence default ctor" << endl;
}

Sequence::Sequence(int value) :
	before{value - 1},
	value{value},
	after{value + 1}
{
	cout << "Sequence ctor: " << value << endl;
}

Sequence::~Sequence(void)
{
}

void Sequence::setValue(int value)
{
	cout << "Sequence::setValue: " << value << endl;
	before = value - 1;
	this->value = value;
	after = value + 1;
}

ostream& operator<<(ostream& out, Sequence& seq)
{
	out << "Sequence["
		<< seq.before << ", "
		<< seq.value << ", "
		<< seq.after << "]";
	
	return out;
}
