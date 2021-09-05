#include <iostream>
#include <stdlib.h>

int main(int argc, char** argv)
{
	unsigned int		n{atoi(argv[1])};
	unsigned int		mul31{31 * n};
	unsigned int		shift5m1{(n << 5) - n};

	std::cout << mul31 << " " << shift5m1 << std::endl;

	return 0;
}
