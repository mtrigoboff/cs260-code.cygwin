#ifndef _FACTORIAL_
#define _FACTORIAL_

class Factorial
{
public:
	Factorial(int n);
	Factorial();			// default constructor

private:
	static int fact(int n);	// computes factorial of n

	int		n;
	int		f;				// factorial of n
};

#endif	// _FACTORIAL_
