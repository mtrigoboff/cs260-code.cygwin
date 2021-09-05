#include <iostream>
#include <memory>
#include "str.h"

#pragma GCC diagnostic ignored "-Wunused-variable"

using namespace std;

// gdb runs into a bug printing out instance of unique_ptr."

int main(int argc, char** argv)
{
	if (argc > 1)				// turn off cout
		std::cout.setstate(std::ios_base::badbit);

	unique_ptr<Str>		up1{new Str{"unique"}};
	// unique_ptr<Str>	up2(up1);				// won't compile
	unique_ptr<Str>		up2{std::move(up1)};

	Str*				us1{up1.get()};
	Str*				us2{up2.get()};

	cout << "us1 = " << us1 << endl;
	cout << "us2 = " << us2 << endl << endl;

	shared_ptr<Str>		sp1{new Str{"shared"}};
	shared_ptr<Str>		sp2{sp1};

	Str*				ss1{sp1.get()};
	Str*				ss2{sp2.get()};

	cout << "ss1 = " << sp1 << endl;
	cout << "ss2 = " << sp2 << endl << endl;

	return 0;
}
