#include <iostream>
#include "str.h"

using namespace std;

int main(int argc, char** argv)
{
	if (argc > 1)				// turn off cout
		std::cout.setstate(std::ios_base::badbit);

	Str		s1{"xyz"};
	Str		s2{"def"};
	Str		s3;
	Str		s4{std::move(s1)};
	Str		s5{s2};

	s3 = s1;
	s3 = Str{"abc"};
	s3 = s1;

	return 0;
}
