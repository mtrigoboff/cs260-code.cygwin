#include <iostream>
#include "noinitlists.h"
#include "yesinitlists.h"

using namespace std;

// This code demonstrates that a default constructor can be called
// when you might not have anticipated that it would happen. This
// code causes such a call to the default constructor for the
// Sequence class.
//
// The way to keep this from happening is to use initialization lists
// when writing constructors.

int main(int argc, char** argv)
{
	if (argc > 1)				// turn off cout
		std::cout.setstate(std::ios_base::badbit);

	// create instance of Sequence on stack
	cout << "creating instance of Sequence on stack" << endl;
	Sequence		seq{5};
	cout << seq << endl << endl;

	// create instance of YesInitLists on stack
	cout << "creating instance of YesInitLists on stack" << endl;
	YesInitLists	yes{1, 5, 9};
	cout << yes << endl << endl;

	// create instance of NoInitLists on stack
	cout << "creating instance of NoInitLists on stack" << endl;
	NoInitLists		no{1, 5, 9};
	cout << no << endl << endl;

	return 0;
}
