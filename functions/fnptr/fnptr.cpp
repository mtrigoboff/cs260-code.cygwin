#include <iostream>

using namespace std;

typedef void (*FnPtr)(int& n);

static void incr(int& n)
{
	cout << "incr" << endl;
	n++;
}

static void decr(int& n)
{
	cout << "decr" << endl;
	n--;
}

int main()
{
	FnPtr	fPtr;
	int		n{3};

	cout << "n = " << n << endl << endl;

	fPtr = incr;
	(*fPtr)(n);
	cout << "n = " << n << endl << endl;

	fPtr = decr;
	(*fPtr)(n);
	cout << "n = " << n << endl << endl;

	return 0;
}
