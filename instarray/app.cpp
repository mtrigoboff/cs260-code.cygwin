#include <ostream>
#include "someclass.h"

#pragma GCC diagnostic ignored "-Wunused-variable"

int main()
{
	SomeClass	sca[2];
	SomeClass	sca2[] = {SomeClass(1), SomeClass(2)};

	return 0;
}
