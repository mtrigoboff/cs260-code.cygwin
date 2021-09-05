#include <iostream>
#include <stdlib.h>
#include "cout_colors.h"
#include "arraybinarysearch.h"

using namespace std;
using namespace cout_colors;

const char * const bool2str(bool b)
{
	return b ? "true" : "false";
}

int main(int argc, char** argv)
{
	if (argc == 1 || argc > 4) {
		cout << "command line args:" << endl
			 << "   searchFor: which character to search for" << endl
			 << "   nItems:    (optional) array size (legal values are 1 through 26, defaults to 26)" << endl
			 << "   noPrint:   (optional, actual value is ignored, requires presence of nItems)" <<  endl
			 << "              if present will turn off printing to avoid messing up gdb tui display" << endl;
		return -1;
		}
	else if (argc == 4)
		// turn off cout, to avoid messing up gdb display
		std::cout.setstate(std::ios_base::badbit);

	int					sizeArg{argc >= 3 ? atoi(argv[2]) : -1};
	int					size{sizeArg < 1 || sizeArg > ArrayBinarySearch::MAX_SIZE ? ArrayBinarySearch::MAX_SIZE : sizeArg};
	ArrayBinarySearch	abs{size};

	char				searchFor{argv[1][0]};
	bool				found;

	cout << BOLD << BLUE << "Binary Search" << endl << endl;
	found = abs.find_iterative(searchFor);
	cout << BOLD << BLUE << (found ? "found" : "not found") << endl;
	cout << endl;
	found = abs.find_recursive(searchFor);
	cout << BOLD << BLUE << (found ? "found" : "not found") << endl;
	cout << RESET << endl;

	return 0;
}
