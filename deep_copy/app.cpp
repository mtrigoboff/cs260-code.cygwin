#include "string.h"
#include "string_shallow.h"

#pragma GCC diagnostic ignored "-Wunused-variable"

int main(int argc, char** argv)
{
	// deep copy
	{
	String*		str1{new String{"abc"}};
	String		str2{"def"};
	String		str3{*str1};
	String		str4{str2};
	String		str5;

	str4 = *str1;

	str5 = str4;

	delete str1;
	}

	// shallow copy
	if (argc > 1) {
		StringShallow	str1{"abc"};
		StringShallow	str2{str1};
		}

	return 0;
}
