#include <iostream>
#include "array.h"

using namespace std;

static const int SIZE{5};

int main(int argc, char **argv)
{
	if (argc > 1)				// turn off cout
		std::cout.setstate(std::ios_base::badbit);

	Array	ar{5};

	for (int i{0}, ch{'a'}; i < SIZE; i++, ch++)
		ar.set(i, ch);

	cout << ar << endl;

	return 0;
}
