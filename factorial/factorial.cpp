#include "factorial.h"

using namespace std;

Factorial::Factorial(int n) :
	n{n}, f{fact(n)}
{
}

Factorial::Factorial() :
	n{-1}, f{-1}
{
}

int Factorial::fact(int n)
{
	if (n == 1)
		return 1;
	else
		return n * fact(n - 1);
}
