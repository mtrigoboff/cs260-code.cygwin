#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

#include <cstring>

int main(int argc, char** argv)
{
	bool	eq;
	char*	str1{"abc"};
	char*	str2{"abc"};
	char*	str3{argc > 1 ? argv[1] : const_cast<char*>("abc")};

	if (str1 == str2)
		eq = true;
	
	if (str1 == str3)
		eq = true;
	
	if (strcmp(str1, str3) == 0)
		eq = true;
	
	return 0;
}
